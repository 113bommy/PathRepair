n, m = map(int, input().split())

a, b = [], []

for i in range(m):
    ab = input().split()
    a.append(ab[0])
    b.append(ab[1])

c = input().split()

o = ''.join([i if len(a[a.index(i)]) >= len(b[a.index(i)]) else b[a.index(i)] for i in c])

print(o)
