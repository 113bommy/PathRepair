n, k = map(int, input().strip().split())
k -= (n * 2)
if k == 0:
    ans = n
else:
    if k // n > 0:
        ans = 0
    else: 
        ans = n - (k % n)
    print(ans)