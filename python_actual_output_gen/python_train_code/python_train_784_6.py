i = input
a = i()
b = i()
c = str(int(a) + int(b))
a = a.replace(' ', '')
b = b.replace(' ', '')
c = c.replace(' ', '')
print('YES' if int(a) + int(b) == int(c) else 'NO')