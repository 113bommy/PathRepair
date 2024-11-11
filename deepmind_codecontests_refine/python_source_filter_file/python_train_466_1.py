def points(t, w, x):
    return max(0.3 * x, x - x * t // 250 - 50 * w)

p = [500, 1000, 1500, 2000, 2500]
res = 0
t = tuple(map(int, input().split()))
w = tuple(map(int, input().split()))
for i in range(5):
    res += points(t[i], w[i], p[i])
    
g, b = tuple(map(int, input().split()))
res += 100 * g - 50 * b
print(res)