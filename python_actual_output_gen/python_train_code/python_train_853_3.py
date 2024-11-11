n, = map(int, input().split())
data = input()

a = data[:n]
b = data[n:]

a = list(map(int, a))
b = list(map(int, b))

a.sort()
b.sort()

c1 = c2 = True
for i in range(n):
    if a[i] < b[i]: c1 = False
    if a[i] > b[i]: c2 = False

print('YES' if c1 is True or c2 is True else 'NO')
