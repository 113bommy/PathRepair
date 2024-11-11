n=int(input())
xs=[]
hs=[]
for _ in range(n):
    x,h=list(map(int,input().split()))
    xs.append(x)
    hs.append(h)
ans=2
trees_fell=[]
for i in range(1,n-1):
    if xs[i]-hs[i]>xs[i-1]:
        trees_fell.append(i)
        ans+=1

    elif  xs[i]+hs[i]<xs[i+1] :
        trees_fell.append(i)
        ans += 1
        xs[i]=xs[i] + hs[i]
# print(*trees_fell)
print(ans)