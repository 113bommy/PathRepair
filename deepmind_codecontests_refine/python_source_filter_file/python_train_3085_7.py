from collections import deque
a,b=map(int,input().split())
m=list(map(int,input().split()))
visited=[False]*a
d=[]
for i in range(a):
    d.append(deque())
for i in range(b):
    e,f=map(int,input().split())
    d[e-1].append(f-1)
    d[f-1].append(e-1)
r=0
for i in range(a):
    mn=100000009
    if not visited[i]:
        visited[i] = True
        if mn > m[i]:
            mn=m[i]
        while d[i]:
            k = d[i].popleft()
            if not visited[k]:
                visited[k] = True
                for h in d[k]:
                    d[i].append(h)
                if mn > m[k]:
                    mn=m[k]
        r+=mn
print(r)
