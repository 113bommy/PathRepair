n,x = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
cs = {}
for v in a:
    cs[v] = cs.get(v, 0) + 1
t = 0
if x == 0:
    for c in cs.values():
        t += c * (c + 1) // 2
    print (t)
else:
    for v in a:
        t += cs.get(x ^ v, 0)
    print(t // 2)