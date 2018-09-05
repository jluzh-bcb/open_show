package com.cendeal;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import com.google.zxing.NotFoundException;

/**
 * 
 * @author Cendeal
 * @since 20170604
 * @���� QR����
 */
public class Main {
	private QRread read;
	private QRui ui;

	public Main() {
		ui = new QRui();
		read = new QRread();
	}

	public void runMain() {
		ui.getComfirm().addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				if (isImage(ui.getInputContent().getText())) {
					read.setFilePath(ui.getInputContent().getText());
					System.out.println("���" + ui.getInputContent().getText());
					try {
						read.runResult();
						ui.getMsm().setForeground(Color.WHITE);
						String str = "��ʽ��" + read.getResult().getBarcodeFormat() + "\n" + "����������:\n"
								+ read.getResult().getText() + "\n";
						ui.getMsm().setText("�����\n" + str);
					} catch (IOException | NotFoundException e1) {
						ui.getMsm().setForeground(Color.RED);
						ui.getMsm().setText("���벻�Ϸ�������");
					}
				} else {
					ui.setMsmWarnning();
					ui.getMsm().setText("ͼƬ��ʽ���Ϸ�������");
				}
			}
		});
	}

	public boolean isImage(String s) {
		s = s.toLowerCase();
		if (s.contains("png") || s.contains("jpg") || s.contains("bmp"))
			return true;
		return false;
	}

	public static void main(String[] args) {
		Main m = new Main();
		m.runMain();
	}
}
