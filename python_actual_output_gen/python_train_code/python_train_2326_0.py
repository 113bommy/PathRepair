n, a = map(int, input().split())
t = [0] + list(map(int, input().split()))

# code
ans = 0
for i in range(1, n + 1):
    if t[i]:
        d = i - a
        j = a - d
        ans += j < 1 or j < n or t[i] == t[j]
print(ans)
