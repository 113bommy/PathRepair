n, k = map(int, input().split())
ans = 0
time = 240-k
i = 1
spent = 0
while i <= n and spent+5*i <= time:
    spent += 5*i
    i += 1
    ans += 1
print(ans)