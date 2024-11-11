t=int(input())
for i in range(t):
    n=int(input())
    a = list(map(int, input().split()))
    num=max(a)
    ans=-1
    for i in range(n):
        if a[i]==num:
            if i>0 and i<n-1:
                if a[i]>a[i-1] or a[i]>a[i+1]:
                    ans=i+1
                    break
            if i==0 and a[0]!=a[1]:
                ans=1
                break
            if i==n-1 and a[n-1]!=a[n-2]:
                ans=n
                break
    print(ans)




