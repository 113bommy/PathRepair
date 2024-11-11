n=int(input())
a=list(map(int,input().split()))
ans=float("inf")
x=0
b=sum(a)
for i in range(n):
    x+=a[i]
    if i+1<n:
        ans=min(ans,abs(b-2*x))    
print(ans)