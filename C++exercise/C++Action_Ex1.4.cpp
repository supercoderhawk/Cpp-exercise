//C++实践之路1.4题
//Ladder类测试
/*效果如下：由两个Frame以及一个VerBar组成的，
当水平宽度（-个数）设置为-，垂直高度（|个数）设置为(5,2)时，显示如下：
+-----+
  |

  |
+-----+
  |

  |
+-----+
  |

  |
+-----+
*/

#include<iostream>

//定义水平条HorBar类 
class HorBar
{
private:
	//水平宽度
	int horizonWidth;
public:
	//构造函数
	HorBar(){}
	HorBar(int hWid)
	{
		//如果输入的数小于零，提示
		if(hWid<0)
		{
			std::cout<<"输入的水平线数小于零！"<<std::endl;
			return;
		}
		//符合要求的，赋值并显示
		else
		{
			horizonWidth=hWid;
		
		}
	}
	//HorBar析构函数
	~HorBar(){}
	//显示水平条
	void displayHorizon()
	{
		if(horizonWidth<0)
			std::cout<<"输入的水平线小于零，无法显示"<<std::endl;
		else
		{
			std::cout<<"+";
			for(int i=0;i<horizonWidth;i++)
				std::cout<<"-";
			std::cout<<"+"<<std::endl;
		}
	}
};

//定义垂直条VerBar类
class VerBar
{
private:
	//垂直宽度
	int verticalWidth;
public:
	//垂直条的构造函数
	VerBar(){}

	VerBar(int vWid)
	{
		//如果输入的值小于零，提示
		if(vWid<0)
		{
			std::cout<<"输入的垂直宽度小于零！"<<std::endl;
			return;
		}
		else
		//符合条件的，赋值并显示
		{
			verticalWidth=vWid;
		}

	}
	//VerBar析构函数
	~VerBar(){}
	//显示垂直条
	void displayVertical()
	{
		if(verticalWidth<0)
			std::cout<<"输入的垂直线小于零，无法显示"<<std::endl;
		else
		{
			for(int i=0;i<verticalWidth;i++)
				std::cout<<"|"<<std::endl;
		}
	}

};

//定义框架类
//框架类由两个水平条和当中的一个垂直条组成
class Frame:public HorBar,public VerBar
{
private:
	//框架上部水平条
	HorBar upperHorBar;
	//框架中垂直条
	VerBar middleVerBar;
	//框架中水平条
	HorBar lowerHorBar;

public:
	//定义框架类构造函数
	Frame(){}
	Frame(int hWid,int vWid):
	  upperHorBar(hWid),
	  middleVerBar(vWid),
	  lowerHorBar(hWid){}
	
	//定义框架类析构函数
	~Frame(){}
	//显示框架
	void displayFrame()
	{
		upperHorBar.displayHorizon();
		middleVerBar.displayVertical();
		lowerHorBar.displayHorizon();
	}
};

//定义阶梯类
class Ladder:public Frame
{
private:
	//定义上部框架
	Frame upperFrame;
	//定义中部的垂直条
	VerBar middleVerBar;
	//定义下部的框架
	Frame lowerFrame;

public:
	//定义阶梯类构造函数
	Ladder(){}
	Ladder(int hWid,int vWid):
	  upperFrame(hWid,vWid),
	  middleVerBar(vWid),
	  lowerFrame(hWid,vWid){}
  //定义阶梯类析构函数
	  ~Ladder(){}
	  //显示阶梯
	  void displayLadder()
	  {
		  upperFrame.displayFrame();
		  middleVerBar.displayVertical();
		  lowerFrame.displayFrame();
	  }

};

//main函数测试
int main(int argc,char* argv)
{
	//创建阶梯对象
	Ladder ladder(-5,-2);
	//显示阶梯
	ladder.displayLadder();
	return 0;
}
