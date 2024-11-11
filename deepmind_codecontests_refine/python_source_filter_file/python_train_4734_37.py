s = input()
s = s[:-1]
s = s.strip().lower()

if s[-1] in 'aeiou':
    print('YES')
else:
    print('NO')
