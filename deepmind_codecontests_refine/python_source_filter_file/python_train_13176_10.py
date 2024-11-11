n, m = map(int, input().split())
I = lambda x: {input() for _ in range(x)}
p = I(n)
e = I(m)
c = len(p - e)
print("YNEOS"[1-int(len(p) + min(c, 1) > len(e))::2])