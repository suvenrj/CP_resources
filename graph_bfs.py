from collections import deque
from collections import defaultdict
graph=[[1,3],[0,2],[1,3],[0,2]]
visited=[]
d=defaultdict(int)
bfs=deque()
bfs.append(0)
while(bfs!=deque()):
    if (d[bfs[0]]==0):
        x=bfs.popleft()
        d[x]=1
        visited.append(x)
        for y in graph[x]:
            if(d[y]==0):
                bfs.append(y)
    else:
        bfs.popleft()
print(visited)

