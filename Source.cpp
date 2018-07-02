#include <iostream>

using namespace std;

class CompleteBinaryTree
{
	int CurSize;
	int MaxSize;
	int * List;

public:

	CompleteBinaryTree()
	{
		CurSize=0;
		MaxSize=0;
		List=NULL;
	}

	CompleteBinaryTree(int MaxSize)
	{
		this->MaxSize=MaxSize;
		this->CurSize=0;
		this->List=new int[MaxSize];
	}

	bool Is_Full()
	{
		return (CurSize==MaxSize-1);
	}

	int parent(int Position)
	{
		return (Position-1)/2;
	}

	void swap(int & a, int & b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	void insert(int val)
	{
		if(Is_Full())
		{
			cout<<"List Full"<<endl;
		}

		else
		{

		int Position=CurSize;

		List[CurSize++]=val;

		while(Position!=0 && List[Position]>List[parent(Position)])
		{
			swap(List[Position],List[parent(Position)]);
			Position=parent(Position);
		}
		}
	}


	void show()
	{
		for(int i=0;i<CurSize;i++)
		{
			cout<<List[i]<<endl;
		}
	}

	~CompleteBinaryTree()
	{
		delete [] List;
	}
};

void main()
{
	CompleteBinaryTree obj(8);
	obj.insert(4);
	obj.insert(5);
	obj.insert(8);
	obj.insert(9);
	obj.insert(10);
	obj.insert(6);
	obj.insert(2);
	obj.insert(1);
	obj.show();

}