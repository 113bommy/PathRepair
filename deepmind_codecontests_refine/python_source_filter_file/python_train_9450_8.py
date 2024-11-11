n, k = map(int, input().split())
a = list(map(int, input().split()))
s = 1
c = 0
d = {}
t = []
# 順番をdictで持つ
while not s in d.keys():
    d[s] = c
    t.append(s)
    c += 1
    s = a[s-1]
l = c - d[s]
m = len(d.keys()) - l
if m >= k:
    print(t[m])
else:
    print(t[(k - m) % l + m])

