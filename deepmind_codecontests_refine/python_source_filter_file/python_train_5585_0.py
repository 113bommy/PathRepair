n,u=[int(x) for x in input().split()]
a=list(map(int,input().split()))
idx=0
ans=-1
for i in range(n):
    while(idx<n-1 and a[idx]-a[i]<=u):
        idx+=1
    if(idx-i<2):
        continue
    ans=max(ans,(a[idx-1]-a[i+1])/(a[idx-1]-a[i]))
print(ans)