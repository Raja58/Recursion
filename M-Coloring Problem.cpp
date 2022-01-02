// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        01 Jan 2022
//  @Detail  :        M-Coloring Problem (GeeksforGeeks)
//  ============================
//  -->


bool mColor(int node, int &n, int &m, vector<int> color, bool graph[101][101])
{
    if(node == n)
        return true;
        
    for(int col = 1; col <= m; col++)
    {
        bool sameCol = false;
        for(int adj = 0; adj < n; adj++)
        {
            if(graph[node][adj] == 0)
                continue;
            if(color[adj] == col)
            {
                sameCol = true;
                break;
            }
        }
        if(sameCol == true)
            continue;
        color[node] = col;
        if(mColor(node + 1, n, m, color, graph))
            return true;
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n + 1, 0);
    color[0] = 1;
    return mColor(1, n, m, color, graph);
}
