def f(s):
    i = (s // 50) % 475
    l = [26 + i]
    for j in range(25):
        i = (i * 96 + 42) % 475
        l.append(26 + i)
    return l

p, x, y = map(int, input().split())

i = x
while i >= y:
    i -= 50
    if f(i).count(p) > 0:
        break
if i >= y:
    print(0)
    exit(0)

i = x
c = 0
while True:
    if f(i).count(p) > 0:
        break
    i += 50
    c += 1

#print(i)

if c % 2 == 1:
    print((c + 1) // 2)
else:
    print(c // 2)

#print(f(7258 + 150))
