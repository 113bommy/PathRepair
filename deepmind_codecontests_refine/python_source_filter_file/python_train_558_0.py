n, t, p = int(input()), set(input().split()), []
if '100' in t:
    p.append('100')
    t.remove('100')
if '0' in t:
    p.append('0')
    t.remove('0')
k = len(p)
for i in range(10, 100):
    if str(i) in t:
        p.append(str(i))
        break
for i in range(1, 10):
    if str(i) in t:
        p.append(str(i))
        break
if k == len(p) and t: p.append(t.pop())
print(len(p))
print(' '.join(p))