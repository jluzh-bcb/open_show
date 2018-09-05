package gametwo;

import java.io.FileNotFoundException;
import java.io.IOException;


public class Test {

	
	@SuppressWarnings("unused")
	public static void main(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {

		LogicAndUI l=new LogicAndUI();


	}

}
/*
 * 总结；
 * 难题：UI布局，游戏逻辑,UI更新
 * 1.UI布局：JPanel的布局管理器（BordeLayout,GridLayout,FlowLayout)
 * 2.游戏逻辑：生成雷区（Math.Random()),计算周围雷数目，雷数据结构，随机打开周围
 * 3.UI更新
*/
