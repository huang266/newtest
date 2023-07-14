#include<bits/stdc++.h>
using namespace std;
#define MAX 100
typedef struct Arcnode{
	int adjvex;
	struct Arcnode *nextarc;
} Arcnode;
typedef struct Vnode{
	char data;
	Arcnode *firstarc;
}Vnode,AdjList[MAX];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;
int locate(ALGraph &G,char v){
	int i=0;
	for(;i<G.vexnum;i++){
		if(G.vertices[i].data==v)break;
	}
	if(i>G.vexnum)return -1;
	return i;
}
void Create(ALGraph &G){
	cin>>G.vexnum>>G.arcnum;
	for(int i=0;i<G.vexnum;i++){
		cin>>G.vertices[i].data;
		G.vertices[i].firstarc=NULL;
	}
	for(int k=0;k<G.arcnum;k++){
		char v1,v2;
		cin>>v1>>v2;
		int i=locate(G,v1);
		int j=locate(G,v2);
		Arcnode *p1=new Arcnode;
		p1->adjvex=j;
		p1->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=p1;
		Arcnode *p2=new Arcnode;
		p2->adjvex=i;
		p1->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=p2;
	}
}
bool visited[MAX];
void DFS_AL(ALGraph &G,int v){
	cout<<G.vertices[v].data;
	visited[v]=true;
	Arcnode *p=G.vertices[v].firstarc;
	while(p!=NULL){
		int w=p->adjvex;
		if(!visited[w])DFS_AL(G,w);
		p=p->nextarc;
	}
}
int main(){
	ALGraph G;
	Create(G);
	DFS_AL(G,0);
	return 0;
}
