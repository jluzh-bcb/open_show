package gametwo;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;


/**
 * 
 * @author Cendeal
 * @since 20170529-20170530
 * @about UI布局
 */

public class MineClearanceUI extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JButton[][] jbt_area;
	private JTextField jtf_landMineCount;
	private JLabel boomCount;
	private JButton jbt_restart;
	private JComboBox<String> jbox_more;
	private JPanel grid; 

	public MineClearanceUI(int height, int lenght) {
		//框架设置
		setLayout(new BorderLayout(10,20));
		setSize(lenght*45, height*40);
		setTitle("Cendeal的粽子游戏，端午没粽子吃");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//布局内容
		grid = new JPanel(new GridLayout(height, lenght));
		jbt_area = new JButton[height][lenght];
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < lenght; j++) {
				jbt_area[i][j] = new JButton();
				jbt_area[i][j].setFont(new Font("", Font.CENTER_BASELINE,13));
				jbt_area[i][j].setBackground(Color.white);
				jbt_area[i][j].setForeground(Color.WHITE);
				grid.add(jbt_area[i][j]);	
			}
		}
		JPanel grid2= new JPanel(new FlowLayout(FlowLayout.CENTER,2,20));	
		jtf_landMineCount=new JTextField("16",8);
		boomCount=new JLabel("粽子个数：");
		boomCount.setFont(new Font("宋体",Font.PLAIN,20));
		//选择项
		 jbox_more=new JComboBox<String>();
		 jbox_more.addItem("16X16");
		 jbox_more.addItem("12X16");
		 jbox_more.addItem("9X9");
		//重新开始按钮
		jbt_restart=new JButton("重新开始");
		jbt_restart.setFont(new Font("雅黑",Font.PLAIN,20));
		grid2.add(boomCount);
		grid2.add(jtf_landMineCount);
		grid2.add(jbox_more);
		grid2.add(jbt_restart);
		add(grid2,BorderLayout.NORTH);
		add(grid);	
		setVisible(true);
	}

	//getter and setter 
	public JButton getJbt_area(int i,int j) {
		return jbt_area[i][j] ;
	}
	
	public JButton getJbt_restart() {
		return jbt_restart;
	}

	public void setJbt_restart(ActionListener e) {
		this.jbt_restart.addActionListener(e);;
	}
	
	public JTextField getJtf_landMineCount() {
		return jtf_landMineCount;
	}
	
	public JComboBox<String> getJbox_more() {
		return jbox_more;
	}
	//重置
	public void resetUI(int height, int lenght){
		grid.removeAll();
		grid.setLayout(new GridLayout(height, lenght));
		jbt_area = new JButton[height][lenght];
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < lenght; j++) {
				jbt_area[i][j] = new JButton();
				jbt_area[i][j].setFont(new Font("", Font.CENTER_BASELINE,13));
				jbt_area[i][j].setBackground(Color.white);
				jbt_area[i][j].setForeground(Color.WHITE);
				grid.add(jbt_area[i][j]);
			}
		}
		grid.revalidate();
		add(grid);
	}

}
