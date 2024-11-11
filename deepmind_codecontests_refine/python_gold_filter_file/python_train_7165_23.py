n, *p = map(int, open(0).read().split())
s = sum(j - i - max(0, i - j) - max(0, j - i)%2 for i, j in zip(p, p[n:]))
print("Yes" if s >= 0 == s%2 else "No")