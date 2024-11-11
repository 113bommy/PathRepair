n,k = list(map(int,input().split()))
ans = [0]*n
if n==1 and k==1:
    print(-1)
elif (n-k)%2==0:
    for i in range(0,n-k,2):
        ans[i] = i+2
        ans[i+1] = i+1
    for i in range(n-k,n):
        ans[i] = i+1
    print(*ans)
else:
    ans[0] = 1
    for i in range(1,n-k,2):
        ans[i] = i+2
        ans[i+1] = i+1
    for i in range(n-k,n):
        ans[i] = i+1
    print(*ans)