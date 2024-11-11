s = input()
a = ''

for _ in s:
    if _ == 'B':
        a = a[:-1]
    else:
        a += _

print(a)