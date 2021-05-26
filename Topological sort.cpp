vector<int> TopologicalSort(vector<vector<int>> &AdjList){

    int n = AdjList.size();

    vector<int> sortedList;

    // we will create a vector the indegree of all vertices
    vector<int> indegree(n);

    for(auto x: AdjList){
        for(auto y: x){
            indegree[y]++;
        }
    }

    // we will make a queue which will store all the vertices with zero indegree making in independent of any other vertices
    queue<int> q;

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int curr = q.front();
        sortedList.push_back(curr);
        q.pop();
        for(auto x: AdjList[curr]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }

    for(int i=0;i<n;i++){
        // if indegree of any vertices is grater than zero now the it must contains a cycle
        // a cyclic directed graph can not have any topological sort
        if(indegree[i]>0){
            return {}; // returning a empty vector. cycle is present
        }
    }
    reverse(sortedList.begin(),sortedList.end());

    return sortedList;
}