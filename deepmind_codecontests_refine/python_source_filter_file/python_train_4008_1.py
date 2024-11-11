inp = lambda : map(int, input().split())
n, w = inp()
a = sorted([*inp()])
print(min(w, min(a[-1] / 2, a[n - 1]) * n * 3))
