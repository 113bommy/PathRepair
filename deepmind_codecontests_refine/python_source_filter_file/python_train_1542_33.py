n = int(input())
a = input()
r = [None] * (n + 1)
for i in range(n, 0, -1):
    r[i] = (ord(a[2 * i - 1]) + sum(r[i * 2::i])) % 2
print(r.count(1))
print(*(i for i, x in enumerate(r) if x))
