import sys
input=sys.stdin.readline
import collections
from collections import defaultdict

visited=set()
mem=[]
G=defaultdict(list)
n=int(input())
l=[int(i) for i  in input().split()]
l=[i for i in l if i>0]

if len(l)>=120 :
    print(3)
elif len(l)<3:
    print(-1)
else:
    for i in range(1,len(l)):
        for j in range(0,i):
            if l[i]&l[j]!=0:
                G[i].append(j)
                G[j].append(i)
    #print(G)
    min_cycle = n + 1
    for key, _ in G.items():
        #print(key,_)
        qu = collections.deque()
        qu.append((key, 0, None))
        visited = {}
        while len(qu) > 0:
            #print(qu,visited)
            node = qu.popleft()
            visited[node[0]] = node[1]
            for child in G[node[0]]:
                if child not in visited:
                     qu.append((child, node[1] + 1, node[0]))
                     #print(qu)
                else:
                    if node[2] != child:
                        min_cycle = min(min_cycle, visited[child] + node[1] + 1)
                        #print(min_cycle,visited[child],node[1])
    if min_cycle == n + 1:
        print(-1)
    else:
        print(min_cycle)

    
