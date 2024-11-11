n = int(input())
m = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

p = []

p.append(a[0])
for i in range(1, n):
    p.append(b[i])
    p.append(a[i])
p.append(b[0])

print(p)

p.reverse()

t = []
t.append(0)
able = True

for i in range(1, 2 * n):
    if p[i-1] == 1:
        able = False
        break
    else:
        t.append((m + p[i-1] * t[i-1]) / (p[i-1] - 1))


lp = p[2*n-1]

if lp == 1:
    print(-1)
else:
    if not able:
        print(-1)
    else:
        lt = t[2*n-1]
        print((m + lp * lt) / (lp - 1))