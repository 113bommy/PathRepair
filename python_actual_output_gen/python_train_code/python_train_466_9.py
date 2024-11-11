s = input()
o = s.count('o')
d = s.count('d')
if o == 0 or d == 0 or d % o == 0:
    print('YES')
else:
    print('NO')