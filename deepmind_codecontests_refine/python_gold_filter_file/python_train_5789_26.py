l = []
r = []
s = []
p = []
for i in range(4):
    d = list(map(int, input().split()))
    l.append(d[0])
    s.append(d[1])
    r.append(d[2])
    p.append(d[3])
t="NO"
if p[0] and (r[3] or s[2] or l[1] or s[0] or l[0] or r[0]):
    t = "YES"
if p[1] and (r[0] or s[3] or l[2] or s[1] or l[1] or r[1]):
    t = "YES"
if p[2] and (r[1] or s[0] or l[3] or s[2] or l[2] or r[2]):
    t = "YES"
if p[3] and (r[2] or s[1] or l[0] or s[3] or l[3] or r[3]):
    t = "YES"
print(t)