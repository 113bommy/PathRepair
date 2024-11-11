n = input()
n = n.lower()
removed = n.replace(' ', '')

c = removed[-2]
print(c)

if c in 'aeiouy':
    print('YES')
else:
    print('NO')

