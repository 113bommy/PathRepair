n = input()
n = n.lower()
removed = n.replace(' ', '')

c = removed[-2]
print(c)

if c in 'aeiou':
    print('YES')
else:
    print('NO')

