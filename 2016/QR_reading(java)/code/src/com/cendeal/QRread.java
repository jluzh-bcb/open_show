package com.cendeal;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import javax.imageio.ImageIO;
import com.google.zxing.BinaryBitmap;
import com.google.zxing.EncodeHintType;
import com.google.zxing.MultiFormatReader;
import com.google.zxing.NotFoundException;
import com.google.zxing.Result;
import com.google.zxing.client.j2se.BufferedImageLuminanceSource;
import com.google.zxing.common.HybridBinarizer;
/**
 * 
 * @author Cendeal
 * @since  20170604
 * @描述 QR解析逻辑
 */
public class QRread {
	private String filePath;
	private MultiFormatReader formatReader;
	private Result result;

	
	public QRread(){

	
	formatReader=new MultiFormatReader();
	

	}
	
	@SuppressWarnings("unchecked")
	public void runResult() throws NotFoundException, IOException{

		File file=new File(filePath);
		
		BufferedImage img=ImageIO.read(file);
		BinaryBitmap binaryBitmap=new BinaryBitmap(new HybridBinarizer(new BufferedImageLuminanceSource(img)));
		
		@SuppressWarnings("rawtypes")
		HashMap hints=new HashMap();
		hints.put(EncodeHintType.CHARACTER_SET, "utf-8");
		result=formatReader.decode(binaryBitmap,hints);
		System.out.println("解析结果是："+result.toString());
		System.out.println("格式："+result.getBarcodeFormat());
		System.out.println("内容是："+result.getText());
	}
	//setter and getter
	public String getFilePath() {
		return filePath;
	}

	public void setFilePath(String filePath) {
		this.filePath = filePath;
	}
	public Result getResult() {
		return result;
	}
	public void setResult(Result result) {
		this.result = result;
	}

}
