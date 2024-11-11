n = int(input(''))
a = input('').split()
c = list()
for b in a:
    b = int(b)
    c.append(b)
c.sort()
print(a)
if c[n-1] < c[n]:
    print('YES')
else:
    print('NO')
