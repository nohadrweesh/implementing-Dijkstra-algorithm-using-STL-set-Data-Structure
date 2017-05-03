#include <iostream>
#include <vector>
#include <queue>
#include<set>
const int oo = 0x3f3f3f;
using std::set;
using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::swap;
using std::make_pair;
/*class priorityQueue{
private:
vector<pair<int,int>> distsQueue;
void makeMinHeap(int i){
static int size = distsQueue.size();
int  largest = i;
int l = 2 * i + 1;
int r = 2 * i + 2;

if (l < size&&distsQueue[l].second < distsQueue[largest].second)
largest = l;
if (r < size&&distsQueue[r] .second< distsQueue[largest].second)
largest = r;
if (largest != i){
swap(distsQueue[i], distsQueue[largest]);
makeMinHeap(largest);
}
}
int parent(int i){ return ceil((i / 2)-1); }
int leftChild(int i){ return 2 * i + 1; }
int rightChild(int i){ return 2 * i + 2; }
void shiftUp(int i){
while (i>0 && distsQueue[parent(i)].second < distsQueue[i].second){
swap(distsQueue[parent(i)], distsQueue[i]);
i = parent(i);
}
}
void shiftDown(int i){
int maxIndx = i;
int l = leftChild(i);
if (l < distsQueue.size() && distsQueue[l].second < distsQueue[maxIndx].second)
maxIndx = l;
int r = rightChild(i);
if (r < distsQueue.size() && distsQueue[r].second < distsQueue[maxIndx].second)
maxIndx = r;
if (i != maxIndx){
swap(distsQueue[i], distsQueue[maxIndx]);
shiftDown(maxIndx);
}

}

public:
priorityQueue(vector<pair<int,int>> &nodesDists){
distsQueue = nodesDists;
}
void changePriority(int i,int newDist){

shiftDown(i);
}
int getMin(){//return node
return distsQueue[0].first;
}
int extractMin(){
int result = distsQueue[0].first;
distsQueue[0] = distsQueue[distsQueue.size() - 1];
distsQueue.pop_back();
shiftDown(0);
return result;
}

};

void Dijkstra(vector<vector<int> > &adj, int s){
vector<int>dist(adj.size(), oo);
vector<int>prev(adj.size(), -1);
}*/
int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
	//write your code her
	set<pair<int, int>>setDists;
	vector<int>dists(adj.size(), oo);
	setDists.insert(make_pair(0, s));
	dists[s] = 0;
	while (!setDists.empty()){
		pair<int, int>tmp = *(setDists.begin());//weight  vertex
		int u = tmp.second;
		if (u == t)return dists[u];
		setDists.erase(setDists.begin());


		for (int i = 0; i < adj[u].size(); i++){
			int v = adj[u][i];
			int w = cost[u][i];
			if (dists[v]>dists[u] + w){
				if (dists[v] != oo)
					setDists.erase({ dists[v], v });
				//setDists.erase(setDists.find(make_pair(dists[v], v)));
				dists[v] = dists[u] + w;
				setDists.insert(make_pair(dists[v], v));
			}
		}


	}
	if (dists[t] == oo)
		return -1;
	else
		return dists[t];
	//return dists[t];
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y, w;

		std::cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1);
		cost[x - 1].push_back(w);
	}

	int s, t;
	std::cin >> s >> t;
	s--, t--;
	std::cout << distance(adj, cost, s, t) << "\n";
	//system("pause");
}
