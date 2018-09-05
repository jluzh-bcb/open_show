package com.cendeal;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.datatransfer.DataFlavor;
import java.awt.datatransfer.UnsupportedFlavorException;
import java.awt.dnd.DnDConstants;
import java.awt.dnd.DropTarget;
import java.awt.dnd.DropTargetDragEvent;
import java.awt.dnd.DropTargetDropEvent;
import java.awt.dnd.DropTargetEvent;
import java.awt.dnd.DropTargetListener;
import java.io.File;
import java.io.IOException;
import java.util.List;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
/**
 * 
 * @author Cendeal
 * @since 20170604
 * @���� ����
 */
public class QRui extends JFrame implements DropTargetListener {

	private static final long serialVersionUID = 2017060402L;
	private JLabel tips;
	private MJTextArea msm;
	private MJTextArea inputContent;
	private JButton comfirm;

	public QRui() {
		// ��ȡ���ڹ�����
		Toolkit toolkit = this.getToolkit();
		// ����
		Dimension d = toolkit.getScreenSize();
		// �������
		setTitle("(���԰�java)QR������by���ѧԱ");
		setIconImage(new ImageIcon("src\\res\\header.png").getImage());
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 setResizable(false);
		setLayout(new BorderLayout());
		setLocation((d.width - 500) / 2, (d.height - 250) / 2);
		setSize(500, 250);
		// �������
		Font font = new Font("����", Font.PLAIN, 16);
		tips = new JLabel("����Ҫ�����Ķ�ά��ͼƬλ�ã�(֧������,[��ʽ��png,jpg,bmp])");
		//����
		msm = new MJTextArea("�����");
		JScrollPane scroll=new JScrollPane(msm);
		msm.setLineWrap(true);
		msm.setForeground(Color.WHITE);
		msm.setBackground(Color.black);
		msm.setFont(font);
		msm.setEditable(false);
		tips.setFont(font);
		inputContent = new MJTextArea(4, 20);
		inputContent.setLineWrap(true);
		//ʵ������Ч��
		new DropTarget(inputContent, DnDConstants.ACTION_COPY_OR_MOVE, this);
		comfirm = new JButton("ȷ��");

		comfirm.setFont(font);
		// ��������
		JPanel panel = new JPanel(new FlowLayout());
		JPanel panel2 = new JPanel(new FlowLayout());
		JPanel panel3 = new JPanel(new GridLayout(2, 2));

		panel.add(tips);
		panel3.add(inputContent);
		panel3.add(scroll);
		panel2.add(comfirm);
		// ������
		add(panel, BorderLayout.NORTH);
		add(panel3, BorderLayout.CENTER);
		add(panel2, BorderLayout.SOUTH);
		// pack();
		setVisible(true);
	}

	// seter and getter
	public JTextArea getInputContent() {
		return inputContent;
	}

	public void setInputContent(MJTextArea inputContent) {
		this.inputContent = inputContent;
	}

	public JButton getComfirm() {
		return comfirm;
	}

	public void setComfirm(JButton comfirm) {
		this.comfirm = comfirm;
	}

	public MJTextArea getMsm() {
		return msm;
	}

	public void setMsm(MJTextArea msm) {
		this.msm = msm;
	}
//�ӿڷ���
	@Override
	public void dragEnter(DropTargetDragEvent dtde) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void dragOver(DropTargetDragEvent dtde) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void dropActionChanged(DropTargetDragEvent dtde) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void dragExit(DropTargetEvent dte) {
		// TODO Auto-generated method stub
		
	}

	@SuppressWarnings("unchecked")
	@Override
	public void drop(DropTargetDropEvent dtde) {
		dtde.acceptDrop(DnDConstants.ACTION_MOVE);
		try {
			List<File> list = (List<File>) (dtde.getTransferable()
					.getTransferData(DataFlavor.javaFileListFlavor));
			for (File file : list) {
				if(file.isFile()){
				inputContent.setText(file.getAbsolutePath());
				msm.setForeground(Color.white);
				msm.setText("�����");	
				}
				
				else{
					setMsmWarnning();
					msm.setText("�����ļ�����");
				}
					
				System.out.println(file.getAbsolutePath());
			}
			
		} catch (UnsupportedFlavorException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public void setMsmWarnning(){
		msm.setForeground(Color.RED);
	}
}
