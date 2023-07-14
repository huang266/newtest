#include<iostream>
using namespace std;
#define MVnum 100
typedef struct {
	char vex[MVnum];
	int arcs[MVnum][MVnum];
	int vexnum,arcnum;
}AMGraph;
int locate(AMGraph &G,char v){
	int i=0;
	for(;i<G.vexnum;i++){
		if(G.vex[i]==v)break;
	}
	if(i>G.vexnum)return -1;
	return i;
}
void Creat(AMGraph &G){
	cin>>G.vexnum>>G.arcnum;
	for(int i=0;i<G.vexnum;i++)
		cin>>G.vex[i];
	for(int i=0;i<G.arcnum;i++)
	for(int j=0;j<G.arcnum;j++)
	G.arcs[i][j]=0;
	for(int k=0;k<G.arcnum;k++){
		int i,j,w;
		char v1,v2;
		cin>>v1>>v2>>w;
		i=locate(G,v1);
		j=locate(G,v2);
		G.arcs[i][j]=w;
		G.arcs[j][i]=w;}	
}
bool visited[MVnum];
void DFS_AM(AMGraph &G,int v){
	cout<<G.vex[v];
	visited[v]=true;
	for(int i=0;i<G.vexnum;i++)
		if(G.arcs[v][i]!=0&&(!visited[i]))DFS_AM(G,i);	
}
int main(){
	 AMGraph G;
	 Creat(G);
	 DFS_AM(G,0);
	return 0;
}








