n,k,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
b=sum(a)
ans = (b+min(n*k,m))/len(a)
for i in range(n-1):
    b=b-a[i]
    ans=max(ans,(b+min((n-1-i)*k,m-1-i))/(n-1-i))
print(ans)
    
    
