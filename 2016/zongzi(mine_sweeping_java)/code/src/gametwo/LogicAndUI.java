package gametwo;

import java.awt.Color;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JOptionPane;

/**
 * 
 * @author Cendeal
 * @since 20170529
 * @about UI���߼�
 */
public class LogicAndUI {
    
	GameLogic l;
	MineClearanceUI ui;
	
	public LogicAndUI() {
		l = new GameLogic();
		ui = new MineClearanceUI(l.getHEIGHT(), l.getLENGTH());
		ui.setIconImage(new ImageIcon("src\\res\\zongzi.png").getImage());	
		// ����¼�
		// selectedbtn
		addSelectEvent();
		// restratBtn setting
		restartBtn(ui.getJbt_restart());
		for (int i = 0; i < l.getHEIGHT(); i++) {
			for (int j = 0; j < l.getLENGTH(); j++)
				addMouseEventToBtn(ui.getJbt_area(i,j), i, j);
		}

	}

	// �¼�����
	public void addMouseEventToBtn(JButton btn, int positionY, int positionX) {
		btn.addMouseListener(new MouseAdapter() {
			@SuppressWarnings("static-access")
			public void mousePressed(MouseEvent e) {
				System.out.println("tips:"+l.getTips());
				
				if (e.getButton() == e.BUTTON1) {
					// System.out.println(e.getY()+" "+ e.getX());
					// �ȵ�����
					if (l.isLandMine(positionY, positionX)) {

						openAllArea();
						ui.getJbt_area(positionY,positionX).setBackground(Color.YELLOW);

						failMessegeTips("�㲻���Գ����ӣ���Ϸ������\n�Ƿ����", btn);
					} else if (l.getBtnValu(positionY, positionX) == 0 && !l.getBtnMark(positionY, positionX)) {
						// �������Χ
						l.aroundBlank(positionY, positionX);
						openA();	
					} else if (!l.getBtnMark(positionY, positionX)) {
						l.setBtnMark(positionY, positionX);
						btn.setBackground(Color.gray);
						switch(l.getBtnValu(positionY, positionX)){
						case 1:
							btn.setForeground(Color.BLUE);
							break;
						case 2:
							btn.setForeground(Color.GREEN);
							break;
						case 3:
							btn.setForeground(Color.YELLOW);
							break;
						case 4:
							btn.setForeground(Color.RED);
							break;
						}
						btn.setText(Integer.toString(l.getBtnValu(positionY, positionX)));
						l.openLandMineArea();
						System.out.println(l.getTips() + " ");

					}
				} else if (e.getButton() == e.BUTTON3 && !l.getBtnMark(positionY, positionX)) {
					int temp=l.btnswitchFlags(positionY, positionX);
					if(	temp==1){
						btn.setBackground(Color.RED);
						btn.setForeground(Color.white);
						btn.setText("!");
					}
						
					else if(temp==2){
						btn.setForeground(Color.YELLOW);
						btn.setText("?");
						btn.setBackground(Color.BLUE);
					}
						
					else if(temp==0){
						btn.setBackground(Color.WHITE);
						btn.setText("");
					}
						
				}
				if (l.isVictory()) {
					System.out.println("��Ϸ ʤ��");
					// openAllArea();
					winMessegeTips("ʤ���ˣ���Ϸ������\n�Ƿ����", btn);
				}
			}
		});
	}
//
private void openA(){
	for(int i=0;i<l.getHEIGHT();i++){
		for(int j=0;j<l.getLENGTH();j++){
			if(l.isTipsBlock(i, j)){
				switch(l.getBtnValu(i, j)){
				case 1:
					ui.getJbt_area(i,j).setForeground(Color.BLUE);
					break;
				case 2:
					ui.getJbt_area(i,j).setForeground(Color.GREEN);
					break;
				case 3:
					ui.getJbt_area(i,j).setForeground(Color.YELLOW);
					break;
				case 4:
					ui.getJbt_area(i,j).setForeground(Color.RED);
					break;
				}
				ui.getJbt_area(i,j).setText(Integer.toString(l.getBtnValu(i, j)));
				ui.getJbt_area(i,j).setBackground(Color.gray);
			}else if(l.isBlankAndNotMark(i, j))
				ui.getJbt_area(i,j).setBackground(Color.gray);
		}
	}
}
	// ʤ����ʾ
	public void winMessegeTips(String s, JButton btn) {
		int res = JOptionPane.showConfirmDialog(btn, s, "��ϲ", JOptionPane.YES_NO_OPTION);
		if (res == JOptionPane.YES_OPTION) {
			newGame();
		} else {
			System.exit(0);
		}
	}
    //ʧ����ʾ
	public void failMessegeTips(String s, JButton btn) {
		    JOptionPane.showMessageDialog(btn, s, "sorry", 2);
			newGame();
	}
	// ȫ����
	public void openAllArea() {
		for (int i = 0; i < l.getHEIGHT(); i++) {
			for (int j = 0; j < l.getLENGTH(); j++) {
				if(l.getBtnValu(i, j)==-1) {
					setMcon(ui.getJbt_area(i,j));
				}
			}
		}
	}

	// ������Ϸ��ť
	public void restartBtn(JButton btn) {
		btn.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent arg0) {
				if (!ui.getJtf_landMineCount().getText().equals("")) {
					int count = Integer.parseInt(ui.getJtf_landMineCount().getText());
					if (count > 1 && count < (0.86 * l.getHEIGHT() * l.getLENGTH())) {
						System.out.println(count);
						l.setLandMine(count);
						newGame();
					} else {
					JOptionPane.showMessageDialog(btn,"�������䣨2~" + (int) (0.86 * l.getHEIGHT() * l.getLENGTH()) + ")!!!");	
					}
				} else {
					JOptionPane.showMessageDialog(btn,"�������䣨2~" + (int) (0.86 * l.getHEIGHT() * l.getLENGTH()) + ")!!!");
				
				}
			}
		});
	}

	// add select event
	private void addSelectEvent() {
		ui.getJbox_more().addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				switch (ui.getJbox_more().getItemAt(ui.getJbox_more().getSelectedIndex())) {
				case "16X16":
					l.setHEIGHT(16);
					l.setLENGTH(16);
					break;
				case "12X16":
					l.setHEIGHT(12);
					l.setLENGTH(16);
					break;
				case "9X9":
					l.setHEIGHT(9);
					l.setLENGTH(9);
					break;
				}
				System.out.println("[select]" + ui.getJbox_more().getItemAt(ui.getJbox_more().getSelectedIndex()));
			}
		});
	}
	//����Ϸ
	public void newGame(){
		ui.resetUI(l.getHEIGHT(), l.getLENGTH());
		l.resetGame();
		for (int i = 0; i < l.getHEIGHT(); i++) {
			for (int j = 0; j < l.getLENGTH(); j++)
				addMouseEventToBtn(ui.getJbt_area(i,j), i, j);
		}
		ui.setVisible(true);
	}
	//����ͼ��
	public void setMcon(JButton btn) {
		ImageIcon img=new ImageIcon("src\\res\\zongzi.png");
		img.getImage();
		Image temp= img.getImage().getScaledInstance(btn.getWidth(),
				btn.getHeight(), Image.SCALE_DEFAULT);
		img=new ImageIcon(temp);
		btn.setIcon(img);
	}
}
