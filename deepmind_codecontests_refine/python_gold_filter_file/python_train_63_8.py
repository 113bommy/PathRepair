R = lambda: map(int,input().split())
n,k = R()
a = list(R())

ans  = 9999999999
for i in a:
    if k % i == 0 and k >= i:
        ans = min(ans,k//i)

print(ans)
