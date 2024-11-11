n = int(input())
ans = 0

for _ in range(n):
    sol = list(map(int, input().split()))
    if sol.count("1") >= 2:
        ans += 1

print(ans)