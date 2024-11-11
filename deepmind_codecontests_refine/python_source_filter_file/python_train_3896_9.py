s1, s2, f1, f2 = [int(i) for i in input().split()]

if s1 == f1 or s2 == f2:
    print('1', end=' ')
else:
    print('2', end=' ')

if not((s1 % 2 == s2 % 2) ^ (f1 % 2 == f2 % 2)):
    if abs(f1 - s1) == abs(f2 - s2):
        print(1, end=' ')
    else:
        print(0, end=' ')
else:
    print(0, end=' ')

print(max(abs(s1 - f1), abs(s2 - f2)))
