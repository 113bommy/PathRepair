n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = 0
for i in a:
    if k % i == 0:
        ans = max(ans, i)

print(k // ans)
