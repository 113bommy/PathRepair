n, = map(int, input().split())
a = map(int, input().split())
s = 0
d = {}
for x in a:
 s += x
 d[s] = d.get(s, 0) + 1
print(max([d[k] for k in d]))