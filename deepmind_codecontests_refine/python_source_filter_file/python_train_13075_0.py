n, m = map(int, input().split())
t = input()
s = input()
a = []
o = 0
for j in range(n):
    if s[j] != t[j]:
        o += 1
        a += [j + 1]
for i in range(1, m - n):
    oo = 0
    b = []
    for j in range(n):
        if s[i + j] != t[j]:
            oo += 1
            b += [j + 1]
    if oo < o:
        o = oo
        a = b[:]
print(o)
print(*a)