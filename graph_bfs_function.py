from collections import defaultdict,deque
def bfs(root,val):
    bfs = deque(root)
    visited= defaultdict(int)
    count=0
    nodes=[]
    while (bfs!=deque() and count<=val):
        temp = bfs.popleft()
        visited[temp]=1
        count+=1
        nodes.append(temp)
        for node in adjacent[temp]:
            if (visited[node]==0):
                bfs.append(node)
    return nodes