import sys
input=sys.stdin.readline

from collections import defaultdict

def toposort(graph):
    res = []
    found = [0] * len(graph)
    stack = list(range(len(graph)))
    while stack:
        node = stack.pop()
        if node < 0:
            res.append(1+(~node))
        elif not found[node]:
            found[node] = 1
            stack.append(~node)
            stack.extend(graph[node])
 
    # cycle check
    for node in res:
        node-=1
        if any(found[nei] for nei in graph[node]):
            print("NO")
            return
        found[node] = 0
 
    print("YES")
    print(res[::-1])
    
#https://github.com/cheran-senthil/PyRival/blob/master/pyrival/graphs/toposort.py

n,m,k=map(int,input().split())
patterns=set()
pos=dict()

for i in range(n):
    p=input().rstrip()
    patterns.add(p)
    pos[p]=i
    
matches=[[] for _ in range(n)]

chk=True
for i in range(m):
    s,mt=input().rstrip().split()
    mt=int(mt)-1
    if(chk):
        chk=False
        for i in range(1<<k):
            tmp=[]
            for j in range(k):
                if(i&(1<<j)):
                    tmp.append('_')
                else:
                    tmp.append(s[j])
            tmp=''.join(tmp)
            if(tmp in patterns):
                if(mt==pos[tmp]):
                    chk=True #sj should match with old permutation of p[mtj] apparently smh
                else:
                    matches[mt].append(pos[tmp])
                    
if(not chk):
    print("NO")
else:
    toposort(matches)
    
        
            
            
            
        