n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
visited=[False for i in range(n)]
d={a[i]:i for i in range(n)}
print(d)
for i in b:
    x=d[i]
    if visited[x]==True:
        print(0,end=" ")
    else:
        ans=0
        while x>=0 and visited[x]==False:
            ans=ans+1
            visited[x]=True
            x=x-1
        print(ans,end=" ")
    
    


        