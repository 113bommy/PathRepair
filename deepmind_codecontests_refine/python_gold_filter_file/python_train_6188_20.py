n, a, b = map(int, input().split())

arr = [int(z) for z in input().split()]

res = []
for i in arr:
    res.append((i*a) % b // a)

print(*res)