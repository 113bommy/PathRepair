# coding: utf-8
# Your code here!

import sys
readline = sys.stdin.readline
read = sys.stdin.read

n,*p = map(int,read().split())
N = n*n

dist = [0]*N

for a in range(n):
    for b in range(n):
        dist[a*n+b] = min(a,n-1-a,b,n-1-b)

#print(dist)


#ans = [0]*N
ans = 0
iru = [1]*N

for pi in p:
    pi -= 1

    ans += dist[pi]
    iru[pi] = 0

    q = [pi]
    #更新
    
    while q:
        #print(q)
        v = q.pop()
        for i in [-n,-1,1,n]:
            if i==1 and v%n==n-1: continue
            if i==-1 and v%n==0: continue
            nv = v+i
            if 0 <= nv < N and dist[nv] > dist[v] + iru[v]:
                q.append(nv)
                dist[nv] = dist[v] + iru[v]
        
                    
    #print(dist)        

print(ans)







