#include<stdio.h>

typedef struct Tree{
	
	struct Tree* right;
	struct Tree* left;
	int eleman;
	
}BST;

BST* FindParent(BST* root, BST* node)
{
    if (root == node)
        return root; //kok dugumun parenti ondan daha ust býsey olmadýgý ýcýn koku dondursun parent olarak

  while(root != node){
  	
  	if(root->right == node) return root; 
  	if(root->left  == node) return root;
  	
  	BST(root,node->left);
  	BST(root,node->right);
   }
}
