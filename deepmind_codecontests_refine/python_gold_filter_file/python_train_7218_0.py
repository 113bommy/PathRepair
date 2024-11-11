input()
p = ''
s = []
for q in input().split():
    t = q < 'p'
    p += q
    while t and s and s[-1]:
        p += '>'
        s.pop()
        if s: s.pop()
    s.append(t)
    p += '<,'[t]
print(p[:-1] if p.count('<') == p.count('>') else 'Error occurred')