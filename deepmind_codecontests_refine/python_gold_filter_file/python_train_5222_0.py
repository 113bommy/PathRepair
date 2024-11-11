n, h, m = map(int ,input().split())

height = [h for i in range(n)]

for i in range(m):
    l, r, x = map(int, input().split())
    for j in range(l - 1, r):
        height[j] = min(height[j], x)

res = sum(i**2 for i in height)
print(res)