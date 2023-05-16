from collections import defaultdict
graph=[]            #put your graph in 2d array form 
dfs=[]
visited=[]
d=defaultdict(int)
dfs.append(0)
while (dfs!=[]):
    if (d[dfs[-1]]==0):
        x=dfs.pop()
        d[x]=1
        visited.append(x)
        for y in graph[x]:
            if (d[y]==0):
                dfs.append(y)
    else:
        dfs.pop()
print(visited)
