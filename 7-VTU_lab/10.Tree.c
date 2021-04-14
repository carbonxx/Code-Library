/*10. Design, Develop and Implement a menu driven Program in C for the following operations
on Binary Search Tree (BST) of Integers
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
e. Exit*/

#include<stdio.h>
#include<stdlib.h>
typedef struct tree* treeptr;
typedef struct tree{
    int data;
    treeptr llink;
    treeptr rlink;
}tree;
int f=0;
void inOrder(treeptr root){
    if(root){
        inOrder(root->llink);
        printf("%d ",root->data);
        inOrder(root->rlink);
    }
}
void preOrder(treeptr root){
    if(root){
        printf("%d ",root->data);
        preOrder(root->llink);
        preOrder(root->rlink);
    }
}
void postOrder(treeptr root){
    if(root){
        postOrder(root->llink);
        postOrder(root->rlink);
        printf("%d ",root->data);
    }
}
void search(treeptr root,int data){
    if(root){
        if(data<root->data)
            search(root->llink,data);
        else if(data>root->data)
            search(root->rlink,data);
        else{
            f=1;
            return;
        }
    }
}
treeptr newNode(int data){
    treeptr temp=(treeptr)malloc(sizeof(*temp));
    temp->data=data;
    temp->llink=temp->rlink=NULL;
    return temp;
}
treeptr insert(treeptr root,int data){
    if(!root)
        return newNode(data);
    if(data<root->data)
        root->llink=insert(root->llink,data);
    if(data>root->data)
        root->rlink=insert(root->rlink,data);
    return root;
}
treeptr findMin(treeptr root){
    while(root->llink!=NULL)
        root=root->llink;
    return root;
}
treeptr delete(treeptr root,int data){
    if(!root)
        return NULL;
    if(root->data==data){
        if((!root->llink)&&(!root->rlink))
            return NULL;
        else if(root->llink&&!root->rlink)
            return root->llink;
        else if(root->rlink&&!root->llink)
            return root->rlink;
        else{
            int min=findMin(root->rlink)->data;
            root->data=min;
            root->rlink=delete(root->rlink,min);
        }
    }
    else if(data<root->data)
        root->llink=delete(root->llink,data);
    else
        root->rlink=delete(root->rlink,data);
    return root;
}
int main(){
    treeptr root=NULL;
    int a[]={6,9,5,2,8,15,24,14,7,8,5,2};
    int i,n,ch;
    for(i=0;i<12;i++)
        root=insert(root,a[i]);
    printf("\nMENU:\n1.Inorder\n2.PreOrder\n3.PostOrder\n4.Search\n5.Delete\n6.Exit");
    while(1){
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: inOrder(root);
                    break;
            case 2: preOrder(root);
                    break;
            case 3: postOrder(root);
                    break;
            case 4: printf("\nEnter element to be searched:\n");
                    scanf("%d",&n);
                    search(root,n);
                    if(f==0)
                        printf("\nElement not found\n");
                    else
                        printf("\nElement found\n");
                    break;
            case 5: printf("\nEnter element to be deleted\n");
                    scanf("%d",&n);
                    root=delete(root,n);
                    break;
            case 6: exit(0);
        }
    }
}