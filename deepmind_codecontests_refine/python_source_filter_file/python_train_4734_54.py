s = input()
vowels = 'aeiou'
if s.split()[-1] == '?':
    if s.split()[-2][-1] in vowels:
        print('YES')
    else:
        print('NO')
else:
    if s.split()[-1][:-1][-1] in vowels:
        print('YES')
    else:
        print('NO')