//标识符作用域练习
#include<iostream>

//定义World类
class World
{
private:
	const int _identifier;
public:
	//构造函数
	World(int id):_identifier(id)
	{
		std::cout<<"Hello from "<<_identifier<<std::endl;
	}

	void display()
	{
		std::cout<<"测试"<<std::endl;
	}

	//析构函数
	~World()
	{
		std::cout<<"Goodbye from "<<_identifier<<std::endl;
	}
};

int main()
{
	World smallWorld(2);

	for (int i = 3; i<6; i++)
	{
		World aWorld(i);
	}

	World oneMoreWorld(6);

	

	return 0;
}

//构建全局对象
World TheWorld(1);
