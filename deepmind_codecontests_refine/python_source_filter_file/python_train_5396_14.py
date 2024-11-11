from collections import *
h,w=map(int,input().split())
a=[input() for _ in range(h)]
b=[[h*w]*w for _ in range(h)]
b[0][0]=1
d=deque([[0,0]])
while d:
    y,x=d.pop()
    for i,j in([1,0],[-1,0],[0,1],[0,-1]):
        t,u=y+i,x+j
        if h>t>=0<=u<w:
            if a[t][u]=="." and b[t][u]>b[y][x]+1:
                d.append([t,u])
                b[t][u]=b[y][x]+1
print(max(-1,sum([i.count(".") for i in a])-b[-1][-1]))