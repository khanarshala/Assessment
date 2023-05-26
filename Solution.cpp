#include <bits/stdc++.h>
using namespace std;
void print_vector(vector<vector<auto> > v){
   cout << "[";
   for(int i = 0; i<v.size(); i++){
      cout << "[";
      for(int j = 0; j <v[i].size(); j++){
         cout << v[i][j] << ",";
      }
      cout << "]";
   }
   cout << "]"<<endl;
}
class Solution {
   public:
   set<int> visited;
   vector<int> disc;
   vector<int> low;
   int time;
   vector<vector<int> > ret;
   void dfs(int node, int par, vector<int> graph[]) {
      if (visited.count(node))
      return;
      visited.insert(node);
      disc[node] = low[node] = time;
      time++;
      for (int x : graph[node]) {
         if (x == par)
         continue;
         if (!visited.count(x)) {
            dfs(x, node, graph);
            low[node] = min(low[node], low[x]);
            if (disc[node] < low[x]) {
               ret.push_back({ node, x });
            }
         } else{
            low[node] = min(low[node], disc[x]);
         }
      }
   }
   vector<vector<int> > criticalConnections(int n, vector<vector<int> >& v) {
      disc.resize(n + 1);
      low.resize(n + 1);
      time = 0;
      vector<int> graph[n + 1];
      for (int i = 0; i < v.size(); i++) {
         int u = v[i][0];
         int w = v[i][1];
         graph[u].push_back(w);
         graph[w].push_back(u);
      }
      dfs(0, -1, graph);
      return ret;
   }
};
main(){
   Solution ob;
   vector<vector<int>> v = {{0,1},{1,2},{2,0},{1,3}};
   print_vector(ob.criticalConnections(4,v));
}