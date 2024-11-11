n, m = map(int, input().split())
a = []
t = 0
s = 0

for i in range(n):
    a.append(input())

for i in range(n):
    for j in range(m):
        if 'S' not in a[i]:
            t += 1
b = []
c = []
for i in range(m):
    for j in range(n):
        if 'S' in a[j][i]:
            b.append(i)
        else:
            if i not in c:
                c.append(i)
for i in range(len(b)):
    if b[i] in c:
        c.remove(b[i])
s = t + len(c)*n
print(s-(t//n * len(c)))
