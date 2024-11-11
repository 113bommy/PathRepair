import sys
n,m=map(int,sys.stdin.readline().split())
graph=[0]*n
ans=0
for f in range(m):
    u,v=map(int,sys.stdin.readline().split())
    graph[min(u,v)-1]+=1
    if graph[min(u,v)-1]==1:
        ans+=1
q=int(sys.stdin.readline())
for qr in range(q):
    arr=list(map(int,sys.stdin.readline().split()))
    if arr[0]==1:
        graph[min(arr[1],arr[2])-1]+=1
        if graph[min(arr[1],arr[2])-1]==1:
            ans+=1
    elif arr[0]==2:
        graph[min(arr[1],arr[2])-1]-=1
        if graph[min(arr[1],arr[2])-1]==0:
            ans-=1
    else:
        print(ans)