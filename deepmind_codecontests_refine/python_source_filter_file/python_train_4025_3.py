hh, mm = map(int, input().strip().split())
H, D, C, N = map(int, input().strip().split())

x = hh * 60 + mm
y = 20 * 60 + mm
res = C * ((H + N - 1) // N)
if x >= y:
    res *= 0.8
else:
    res = min(res, 0.8 * C * ((H + D * (y - x) + N - 1) // N))
print(res)

