f = lambda: map(int, input().split())
n, k = f()
s = j = 0
for i, q in enumerate(f(), 1):
    if s - j * (n - i) * q < k: print(i)
    else:
        s += q * (i - 1)
        j += 1