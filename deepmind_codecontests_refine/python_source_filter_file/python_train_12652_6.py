f = lambda k: map(int, input().split(k))
a, u = f(' ')
b, v = f(' ')
h, m = f(':')
t = h * 60 + m - 300
x, y = max(t - v, 0), min(t + u, 1139)
print(y // b - x // b)