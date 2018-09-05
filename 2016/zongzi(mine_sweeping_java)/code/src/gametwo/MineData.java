package gametwo;

public //À×Àà½á¹¹
class MineData {
	private int x;
	private int y;
	private int data;
	private boolean mark;
	private boolean willOpening;
	private int flags=0;

	public MineData() {
		setData(0);
		setMark(false);
		setWillOpening(false);
	}
	
	public MineData(int data) {
		setData(data);
		setMark(false);
		setWillOpening(false);
	}
	
	public void xAndY(int y,int x){
		setY(y);
		setX(x);
	}
	public int getData() {
		return data;
	}
	
	public void setData(int data) {
		this.data = data;
	}
	
	public boolean isMark() {
		return mark;
	}
	
	public void setMark(boolean mark) {
		this.mark = mark;
	}

	public void dataAdd() {
		data++;
	}
	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}
	public boolean isWillOpening() {
		return willOpening;
	}

	public void setWillOpening(boolean willOpening) {
		this.willOpening = willOpening;
	}
	public int switchFlags(){
		flags++;
		if(flags==3)
			flags=0;
		return flags;
	}
}
