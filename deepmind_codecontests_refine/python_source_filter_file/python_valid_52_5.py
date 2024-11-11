# cook your dish here
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    a.sort()
    s=[a[0]]
    for i in range(1,n):
        s.append(s[-1]+a[i])
    ans=-10**9
    for i in range(n-1):
        ans=max(ans,s[i]/(i+1)+(s[-1]-s[i])/(n-i-1))
    print(ans)