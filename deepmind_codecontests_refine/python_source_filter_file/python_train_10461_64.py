k, n, w = map(int, input().split())
o = (k + k * w) * w // 2
if o <= 0:
    print(abs(n - o))
else:
    print(0)