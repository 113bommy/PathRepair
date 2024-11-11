n, k, l, c, d, p, nl, np = map(int, input().split())
a = []
x = int(k * l / n);y = c * d;z = int(p / np)
a.append(x);a.append(y);a.append(z)
print(int(min(a) / n))
