n=int(input())
a=list(map(int,input().split()))
s=1
ans=s
for i in range(n-1):
    if a[i]<=a[i+1]:
       s=s+1
    else:
        s=1
    ans=max(s,ans)
print(ans)
        
