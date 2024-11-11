from collections import defaultdict
for _ in range(int(input())):
    n,x=map(int,input().split())
    graph=defaultdict(list)
    for i in range(n-1):
        u,v=map(int,input().split())
        graph[u].append(v)
        graph[v].append(u)
    p=len(graph[x])
    if p==1:
        print("Ayush")
        continue
    if p%2!=0:
        if n%2!=0:
            print("Ashish")
        else:
            print("Ayush")
    else:
        if n%2!=0:
            print("Ashish")
        else:
            print("Ayush")
