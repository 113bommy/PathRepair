def ints():
    return map(int,input().split())
t=int(input())
for _ in range(t):
    n=int(input())
    graph={i:0 for i in range(n)}
    s=input()
    for i in range(n):
        if s[i]=='L':
            graph[i]=(i-1)%n
        else:
            graph[i]=(i+1)%n
    vis=set()
    for i in range(n):
        if graph[graph[i]]==i:
            vis.add(i)
            vis.add(graph[i])
    ans=0
    start=set(range(n))
    for i in range(n):
        if graph[i] in start:
            start.remove(graph[i])
    for v in start:
        curr=1
        currv=v
        while graph[currv] not in vis:
            curr+=1
            currv=graph[currv]
        ans+=(curr+1)//3
    if len(set(s))==1:
        print(1+(n-2)//3)
    else:
        print(ans)
