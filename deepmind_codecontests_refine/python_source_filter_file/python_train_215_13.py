n,s=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
ans=0
if a[n//2]<s:
    for i in range(n//2,n):
        if a[i]>=s:
            break
        else:
            ans+=s-a[i]
    print(ans)
else:
    for i in range((n//2) +1):
        if a[i]<=s:
            break
        else:
            ans+=abs(s-a[i])
    print(ans)
