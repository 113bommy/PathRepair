import math as m

def C(r, n):
    return m.factorial(n) // (m.factorial(r) * m.factorial(max(0, n - r)))

n = int(input())

a = []
res = 0
for i in range(n):
    t = input()
    a.append(t)
    c = 0
    for j in range(n):
        if t[j] == 'C':
            c += 1
    res += C(2, c)
for i in range(n):
    c = 0
    for j in range(n):
        if a[j][i] == 'C':
            c += 1
    res += C(2, c)
print(res)