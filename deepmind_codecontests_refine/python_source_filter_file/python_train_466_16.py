x = [500, 1000, 1500, 2000, 2500]
t = [int(i) for i in input().split()]
w = [int(i) for i in input().split()]
a, b = map(int, input().split())
res = 0.0
for i in range(5):
    y = (1.0 - t[i] / 250.0) * x[i] - 50 * w[i]
    res += max(0.3 * x[i], y)
res += (a * 100 - b * 50)
print(res)
