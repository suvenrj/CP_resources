n=int(input())
from collections import defaultdict
l=[]
for i in range(2,n+1):
    l.append(i)
is_prime = defaultdict(int)
for x in l:
    if (is_prime[x]==0):
        j=1
        while (j*x<=n):
            if (j!=1):
                is_prime[j*x]=1
            j+=1
for keys in is_prime:
    if (is_prime[keys]==0):
        print(keys)
