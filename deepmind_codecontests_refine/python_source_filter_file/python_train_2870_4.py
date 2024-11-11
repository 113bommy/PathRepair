n, m = map(int, input().split())
k = n + 179
for i in range(m):
    l, r = map(int, input().split())
    k = min(k, r - l)

a = [i % k for i in range(n)]

print(k)
print(' '.join(map(str, a)))