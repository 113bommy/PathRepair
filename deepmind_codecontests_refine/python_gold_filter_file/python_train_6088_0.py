# -*- coding: utf-8 -*-
"""
Created on Fri Jun 12 07:48:09 2020

@author: Harshal
"""
import collections
n=int(input())
graph=collections.defaultdict(list)
for i in range(n):
    x,y=input().split("reposted")
    x=x.lower().strip()
    y=y.lower().strip()
    graph[y].append(x)

que=[('polycarp',1)]
seen=set()
ans=0
while que:
    node,depth=que.pop(0)
    
    ans=max(ans,depth)
    for i in graph[node]:
     
        if i not in seen:
            
            seen.add(i)
            que.append((i,depth+1))
   
print(ans)
        
    
