n, v = map(int, input().split())
d = [0] * 3001

for _ in range(n):
    a, b = map(int, input().split())
    d[a - 1] += b

sum = min(v, d[0])
d[0] = max(0, d[0] - v)

for i in range(1, 3001):
    sum += min(v, d[i - 1] + d[i])
    d[i] = max(0, d[i] - max(0, v - d[0]))

print(sum)
