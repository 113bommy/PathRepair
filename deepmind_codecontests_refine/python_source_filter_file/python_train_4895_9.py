n = int(input())
min_v = int(input())
ans = 1 - min_v
for i in range(1, n-1):
    j = int(input())
    ans = max(ans, j - min_v)
    min_v = min(min_v, j)
print(ans)

