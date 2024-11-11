n = int(input())
arr = list(map(int, input().split()))
ans = 0
for i in range(1,31):
    res = 0
    for j in arr:
        res += j
        if j > i:
            res = 0
        res = max(res, 0)
        ans= max(res-i, ans)
print(ans)