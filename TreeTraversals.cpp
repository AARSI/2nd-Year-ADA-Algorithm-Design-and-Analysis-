#include<bits/stdc++.h>
#include<malloc.h>

using namespace std;
struct node
{
    int data;
    node *llink,*rlink;
};
typedef struct node* NODE;
NODE root=0;

class BST
{
    int info;
 public:
     void insert_node();
     void delete_node();
     void inorder(NODE);
     void preorder(NODE);
     void postorder(NODE);


};

// to insert  node
void BST::insert_node()
{
    NODE newnode,temp,prev,cur;
    cout<<"Enter the element to be inserted\n";
    cin>>info;
    newnode= (NODE) malloc(sizeof(struct node));
    newnode->data=info;
    newnode->llink=0;
    newnode->rlink=0;

    if(root==0)
    {
        root=newnode;
        return;
    }

    prev=0;
    cur=root;
    while(cur!=0)
    {
        prev=cur;
        if(info==cur->data)
        {
            cout<<"Duplicate items not allowed\n";
            free(newnode);
            newnode=0;
            return;

        }
        else if(info<cur->data)
        {
            cur=cur->llink;
        }
        else
            cur=cur->rlink;
    }

    if(info<prev->data)
        prev->llink=newnode;
    else
        prev->rlink=newnode;

}


//to delete node
void BST::delete_node()
{
    NODE prev,cur,temp;
    int info;
    cout<<"Enter the element to be deleted\n";
    cin>>info;
    //if tree is empty
    if(root==0)
    {
        cout<<"no element in  the tree\n";
        return;
    }
    prev=0;
    cur=root;
    //if node is root node
    if(cur->llink==0&&cur->rlink==0&&cur->data==info)
    {
        free(root);
        root=0;
        return;
    }

    while(cur!=0)
    {

        if(info==cur->data)
        {
            break;
        }
         prev=cur;
        if(info<cur->data)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }

    if(cur==0)
    {
        cout<<"ELement not found\n";
        return;
    }


    //leaf node
    if(cur->llink==0 && cur->rlink==0)
    {
    if(cur==prev->llink)
    {
        free(cur);
        prev->llink=0;
    }
    else
    {
        free(cur);
        prev->rlink=0;
    }
    return;
    }

    //only one child exists

    if(cur->llink==0 || cur->rlink==0)
    {
        if(cur->llink==0)
        {
            if(cur==prev->llink)
            {
                prev->llink=cur->rlink;
                free(cur);
            }
            else

            {
                prev->rlink=cur->rlink;
                free(cur);
            }
        }

        else if(cur->rlink==0)
        {
            if(cur==prev->llink)
            {
               prev->llink=cur->llink;
               free(cur);
            }
            else
            {
                prev->rlink=cur->llink;
                free(cur);
            }
        }


     return;
    }

    // node with both children

    if(cur->llink!=0 && cur->rlink!=0)
    {
        temp=cur->rlink;
        while(temp->llink!=0)
        {
            prev=temp;
            temp=temp->llink;
        }
        cur->data=temp->data;
        prev->llink=0;
        free(temp);
        temp=0;
        return;
    }
}


void BST::inorder(NODE cur)
{
    if(cur!=0)
    {
        inorder(cur->llink);
        cout<<cur->data<<" ";
        inorder(cur->rlink);

    }
}



void BST::postorder(NODE cur)
{
    if(cur!=0)
    {
        inorder(cur->llink);
        inorder(cur->rlink);
        cout<<cur->data<<" ";

    }
}



void BST::preorder(NODE cur)
{
    if(cur!=0)
    {
        cout<<cur->data<<" ";
        inorder(cur->llink);
        inorder(cur->rlink);

    }
}


int main()
{
    BST B;
    int choice;
    while(1)
    {
    cout<<"1.Insert"<<endl<<"2.Delete"<<endl<<"3.Inorder"<<endl;
    cout<<"4.Preorder"<<endl<<"5.Postorder"<<endl<<"6.exit"<<endl;
    cout<<"Enter ur choice\n";
    cin>>choice;

    switch(choice)
    {
        case 1: B.insert_node();break;
        case 2: B.delete_node();break;
        case 3: B.inorder(root);break;
        case 4: B.preorder(root);break;
        case 5: B.postorder(root);break;
        case 6: exit(0);
    }

    }


}
