#include<bits/stdc++.h>
using namespace std;
struct bfs{
    string a;
    bfs *l,*r;
};
void in_tree(bfs *root);
void build(bfs *&t);
void destory(bfs *root);
int main(void){ 
    while(1){
        bfs *t=0;
        build(t);
        if(t==0) break;
        in_tree(t);
        cout<<endl;
        destory(t);
    }   
}
void in_tree(bfs *root){
    if(root){
	    cout<<root->a;
        in_tree(root->l); 
		in_tree(root->r);
    }
}
void build(bfs *&t){
    string a;
    if(!(cin>>a)||a[0]=='#') return;
    t=new bfs({a,0,0});
    build(t->l);
    build(t->r);
}
void destory(bfs *root){
    if(root){
        destory(root->l);
        destory(root->r);
        delete root;
    }
}
