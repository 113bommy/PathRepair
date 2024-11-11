s, n = [int(x) for x in input().split()]
a = []
b = []
for i in range(n):
    _a, _b = [int(x) for x in input().split()]
    a.append(_a)
    b.append(_b)
p = sorted(zip(a, b), key=lambda x: x[0])

for x in p:
    if s >= x[0]:
        s += x[1]
    else:
        print("NO")
        break
else:
    print("YES")