#include<iostream>
using namespace std;
struct node{
	struct node *left;
	struct node *right;
	int info;
}  *root=NULL;

node *getnode(){
	node *root;
	root=new node;
	return root;
}

node *insert(node *root,int digit)
{
	
	if(root==NULL)
{
	root= getnode();
	root->left=root->right=NULL;
	root->info=digit;
	}

else
{
	if(root->info>=digit){
	root->left=insert(root->left,digit);
	
	}
	else
{
		root->right=insert(root->right,digit);
}
return(root);
}}
void dfs(struct node* root){
	if(root==NULL)
	return;
	cout<<root->info<<" ";
	dfs(root->left);
	dfs(root->right);
	
}
void display(node *root,int space){
	if(root==NULL){
		return;}
	space +=3;
	display(root->right,space);
	cout<<"\n"; 
	for(int i=0; i<space; i++){
		cout<<"   ";
	}
	cout<<root->info;
	cout << endl;
	display(root->left,space);
	
}
int main(){
    root=insert(root,78);
     insert(root,52);
     insert(root,123);
     insert(root,137);
     insert(root,60);
     insert(root,63);
     insert(root,56);
    cout<<"dfs traversal is: ";
	dfs(root);
display(root,0);}

