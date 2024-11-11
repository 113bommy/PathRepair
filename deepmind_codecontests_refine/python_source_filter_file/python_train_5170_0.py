s = [input().lower() for i in range(int(input()))]
u, x = input(), input()
y = 'ab'[x == 'a']
d = [(x, y), (x.upper(), y.upper())]
v = u.lower()
n = len(v)
k = [0] * (n + 1)
for q in s:
    i = v.find(q)
    while i != -1:
        k[i] += 1
        k[i + len(q)] -= 1
        i = v.find(q, i + 1)
p = ''
for i in range(n):
    k[i + 1] += k[i]
    p += d[u[i] == v[i]][x == u[i]] if k[i] else u[i]
print(p)