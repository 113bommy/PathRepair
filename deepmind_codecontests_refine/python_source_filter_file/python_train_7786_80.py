s = int(input())
mx = int(1e9)
x = (mx - s % mx) % mx
y = (s + x) / mx
print(0, 0, mx, 1, x, y)