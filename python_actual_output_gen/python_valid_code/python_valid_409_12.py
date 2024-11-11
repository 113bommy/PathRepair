n = int(input())
a = sorted(map(int, input().split()))
ans = 0
for i in range(n):
    if a[i] >= ans: ans += 1
print(ans)