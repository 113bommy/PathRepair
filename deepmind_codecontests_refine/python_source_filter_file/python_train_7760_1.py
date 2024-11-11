n = int(input())
s = input()

p = set()
for c in s:
    p.add(c)

pc = len(p)

d = dict()
l = 0
r = 0
d[s[r]] = 1
while len(d) < pc:
    r += 1
    if s[r] in d:
        d[s[r]] += 1
    else:
        d[s[r]] = 1
m = r - l

while l + 1 < n:
    d[s[l]] -= 1
    if d[s[l]] == 0:
        del d[s[l]]
    l += 1
    while (r + 1 < n) and (len(d) < pc):
        r += 1
        if s[r] in d:
            d[s[r]] += 1
        else:
            d[s[r]] = 1
    if len(d) < pc:
        break
    m = r - l
         
print(m + 1)

           