#include <iostream>
using namespace std;

class Tree
{
public:
	Tree(){};
	Tree(int n)
	{
		value=n;
		left=NULL;
		right=NULL;
	};
	int value;
	Tree* left;
	Tree* right;
};

Tree* init(int n)
{
	Tree* tree=new Tree(n);
	if(n>2)
	{
		tree->left=init(n-1);
		tree->right=init(n-2);
	}
	return tree;
}

void show(Tree* head)
{
	if(head!=NULL) cout<<head->value<<"\t";
	if(head->left) show(head->left);
	if(head->right) show(head->right);
}


bool hasSub(Tree* tree1,Tree* tree2)
{
	if(!tree2) return true;
	if(!tree1 && tree2) return false;
	if(tree1->value!=tree2->value)
	{
		return hasSub(tree1->left,tree2)||hasSub(tree1->right,tree2);
	}
	else
	{
		while(tree2)
		{
			return hasSub(tree1->left,tree2->left)||hasSub(tree1->right,tree2->right);
		}
		return true;

	}
	return false;
}

int main( )
{
	Tree *tree1=init(5);
	Tree *tree2=init(6);
	Tree *tree3=init(3);
	show(tree1);
	cout<<endl;
	show(tree2);
	cout<<endl;
	show(tree3);
	cout<<endl<<hasSub(tree1,tree2)<<endl;
	cout<<hasSub(tree1,tree3)<<endl;
	return 0;
}