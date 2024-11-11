import collections
import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
t=int(input())
for _ in range(t):
    n,m=map(int,input().split())
    graph1=[]
    graph2=[]
    graph3=[0]*(n+1)
    undirected=[]
    for i in range(n+1):
        graph1.append([])
        graph2.append([])
    for i in range(m):
        t,x,y=map(int,input().split())
        if t==0:
            undirected.append([x,y])
        else:
            graph1[x].append(y)
            graph2[y].append(x)
    s=collections.deque([])
    for i in range(1,n+1):
        if len(graph1[i])==0:
            s.append(i)
    l=[]
    while s:
        p=s.popleft()
        l.append(p)
        for i in graph2[p]:
            m=i
            graph3[i]+=1
            if graph3[i]==len(graph1[i]):
                s.append(i)
    flag=0
    for i in range(1,n+1):
        if graph3[i]!=len(graph1[i]):
            flag=1
            break
    if flag==1:
        print('NO')
        continue
    print('YES')
    for i in range(1,n+1):
        for j in graph1[i]:
            print(i)
            print(j)
    positions=[0]*(n+1)
    for i in range(len(l)):
        positions[l[i]]=i
    for i in range(len(undirected)):
        x=undirected[i][0]
        y=undirected[i][1]
        if positions[x]<positions[y]:
            print(x)
            print(y)
        else:
            print(y)
            print(x)