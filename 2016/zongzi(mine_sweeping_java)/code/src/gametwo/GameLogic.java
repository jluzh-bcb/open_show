package gametwo;


import java.util.LinkedList;
import java.util.Queue;

/**
 * 
 * @author Cendeal
 * @since 20170529
 * @about 游戏逻辑处理
 */
public class GameLogic {
	

	private int HEIGHT = 16;
	private int LENGTH = 16;
	private MineData[][] mapArrays;

	private int LandMine = 16;
	private int tips;

	public void setTips(int tips) {
		this.tips = tips;
	}

	/*
	 * 准备游戏
	 */
	public GameLogic() {
		tips = 0;
		mapArrays = new MineData[HEIGHT][LENGTH];
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < LENGTH; j++) {
				mapArrays[i][j] = new MineData();
				mapArrays[i][j].xAndY(i, j);
			}
		}
		generateLandMine();
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < LENGTH; j++) {
				System.out.print(mapArrays[i][j].getData() + " ");
			}
			System.out.println();
		}
		countTips();
	}

	// 生成地雷
	private void generateLandMine() {
		int i = 0;
		while (i < LandMine) {
			int positionX = (int) (Math.random() * LENGTH);
			int positionY = (int) (Math.random() * HEIGHT);
			if (!isLandMine(positionY, positionX)) {
				mapArrays[positionY][positionX].setData(-1);
				setPistionTipsAdd(positionY, positionX);
				i++;
			}
		}
	}

	// 生成提示
	// ((x-1,y-1),(x,y-1),(x+1,y-1),(x+1,y),(x+1,y+1),(x,y+1),(x-1,y+1),(x-1,y)
	// 注意边界，雷数增加
	/*
	 * [][2]{ {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1} }
	 */
	private void setPistionTipsAdd(int positionY, int positionX) {
		int setp[][] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 } };
		int i = 0;
		while (i < 8) {
			if (!isBoder(positionY + setp[i][0], positionX + setp[i][1])
					&& !isLandMine(positionY + setp[i][0], positionX + setp[i][1])) {
				mapArrays[positionY + setp[i][0]][positionX + setp[i][1]].dataAdd();
			}
			i++;
		}
	}

	// 计算tips
	public void countTips() {
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < LENGTH; j++) {
				if (!isLandMine(i, j) && (mapArrays[i][j].getData() != 0)) {
					tips++;
				}
			}
		}
	}

	/*
	 * 游戏开始
	 */

	// 判断是否踩雷
	public boolean isLandMine(int positionY, int positionX) {
		if (mapArrays[positionY][positionX].getData() == -1)
			return true;
		return false;
	}

	// 打开非雷区
	public void openLandMineArea() {
		tips--;
	}


	// 胜利判断
	public boolean isVictory() {
		if (tips == 0)
			return true;
		return false;
	}

	/*
	 * getter and setter
	 */
	
	public int getLandMine() {
		return LandMine;
	}

	public void setLandMine(int landMine) {
		LandMine = landMine;
	}

	public int getTips() {
		return tips;
	}

	public int getHEIGHT() {
		return HEIGHT;
	}

	public void setHEIGHT(int hEIGHT) {
		HEIGHT = hEIGHT;
	}

	public int getLENGTH() {
		return LENGTH;
	}

	public void setLENGTH(int lENGTH) {
		LENGTH = lENGTH;
	}

	public MineData getMapArrays(int i,int j) {
		return mapArrays[i][j];
	}

	public void setMapArrays(MineData[][] mapArrays) {
		this.mapArrays = mapArrays;
	}

	/*
	 * 辅助判断
	 */
	// 越界判断
	public boolean isBoder(int positionY, int positionX) {
		if (positionY < 0 || positionY >= HEIGHT || positionX >= LENGTH || positionX < 0)
			return true;
		return false;
	}

	// 获取地周围雷数
	public int getBtnValu(int positionY, int positionX) {
		return mapArrays[positionY][positionX].getData();
	}

	// 是否被标记
	public boolean getBtnMark(int positionY, int positionX) {
		return mapArrays[positionY][positionX].isMark();
	}

	// 设置标记
	public void setBtnMark(int positionY, int positionX) {
		mapArrays[positionY][positionX].setMark(true);

	}

	// 是否为空白
	public boolean isBlank(int positionY, int positionX) {
		if (mapArrays[positionY][positionX].getData() == 0)
			return true;
		return false;
	}

	// 重置
	public void resetGame() {
		tips = 0;
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < LENGTH; j++) {
				mapArrays[i][j].setData(0);
				mapArrays[i][j].setMark(false);
				mapArrays[i][j].setWillOpening(false);
				;
			}
		}
		generateLandMine();
		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < LENGTH; j++) {
				System.out.print(mapArrays[i][j].getData() + " ");
			}
			System.out.println();
		}
		countTips();
	}

	// 空白特效
	public void aroundBlank(int positionY, int positionX) {

		mapArrays[positionY][positionX].setWillOpening(true);

		mapArrays[positionY][positionX].setMark(true);
		int setp[][] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 } };

		Queue<MineData> array = new LinkedList<MineData>();

		array.offer(mapArrays[positionY][positionX]);

		while (array.peek() != null) {
			int i = 0;
			int X = array.peek().getX();
			int Y = array.peek().getY();

			while (i < 8) {
				if (!isBoder(Y + setp[i][0], X + setp[i][1])) {
					if (getBtnValu(Y + setp[i][0], X + setp[i][1]) > 0 && !getBtnMark(Y + setp[i][0], X + setp[i][1])) {
						mapArrays[Y + setp[i][0]][X + setp[i][1]].setWillOpening(true);
						openLandMineArea();
						setBtnMark(Y + setp[i][0], X + setp[i][1]);
						System.out.println(("即将打开：" + Y + setp[i][0]) + " " + (X + setp[i][1]));
					} else if (isBlank(Y + setp[i][0], X + setp[i][1]) && !getBtnMark(Y + setp[i][0], X + setp[i][1])) {
						mapArrays[Y + setp[i][0]][X + setp[i][1]].setWillOpening(true);
						setBtnMark(Y + setp[i][0], X + setp[i][1]);
						array.offer(getMapArrays(Y + setp[i][0],X + setp[i][1]));

					}
				}
				i++;
			}
			array.poll();
		}
	}
	//是否提示区
public boolean isTipsBlock(int i,int j){
	if(getMapArrays(i,j).isWillOpening()&&(getMapArrays(i,j).getData())>0)
		return true;
	return false;
}
	//空白且未被标记
public boolean isBlankAndNotMark(int i,int j){
	if(getMapArrays(i,j).isWillOpening()&&isBlank(i, j))
		return true;
	return false;
}

public int btnswitchFlags(int i,int j){
	return mapArrays[i][j].switchFlags();
}
}
