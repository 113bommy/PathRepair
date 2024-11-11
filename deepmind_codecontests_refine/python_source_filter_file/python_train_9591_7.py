n,k = list(map(int,input().split()))
arr = list(map(int,input().split()))
ans=0
for i in range(k):
    s = arr+[0]
    t = i
    while t<n:
        arr[t]=0
        t+=k
    ans=max(ans,abs(sum(arr)))
print(ans)