n,k = map(int,input().split())
ans = 1
if k < 10**5:
    for i in range(1,k+1):
        if n % k != k-1:
            ans = 0
            break
else:
    ans = 0
print("Yes" * ans + "No" * (1 - ans))
