n, k = map(int, input().split())
t = [0] + list(map(int, input().split())) + [k + 1]
for i in range(2, len(t)):
    t[i] += t[i - 1]
i, j, s = 0, 1, 0
while j < n:
    while j < n and t[j] <= k + t[i]: j += 1
    i += 1
    s = max(s, j - i)
print(s)
