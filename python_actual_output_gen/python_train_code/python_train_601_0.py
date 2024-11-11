n = int(input())
b = list(map(int, input().split()))

res = {}
for i in range(n):
    res[b[i] - i] = res.get(b[i] - i, 0) + b[i]
print(max(res.items(), key=lambda x: x[1]))