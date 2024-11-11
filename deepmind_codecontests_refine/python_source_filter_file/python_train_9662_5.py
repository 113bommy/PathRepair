n = int(input())
v = list(map(int, input().split()))
ans = v[0]
for i in range(1, n):
    ans += max(v[i]-v[i-1], 0)
print(cnt)