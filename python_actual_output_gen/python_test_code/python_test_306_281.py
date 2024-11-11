m, n = map(int, input().split())

w = max(m, n)
h = min(m, n)

res = h * (w // 2) + (h // 2) * w % 2
print(res)