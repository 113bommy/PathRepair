n = input()
p = ''
s = []
for q in input().split():
    t = q < 'p'
    p += q
    while t and s and s[-1]:
        p += '>'
        s.pop()
        if s:
            s.pop()
    s.append(t)
    p += "<," [t]
if p.count('<') == p.count('>'):
    print(p[ : -1])
else:
    print("Error occurred.")
