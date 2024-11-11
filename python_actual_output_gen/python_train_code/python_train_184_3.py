s = input()
a, b, c = s.count('a') ,s.count('b'), s.count('c')
lis = sorted([a, b, c])
if lis[2]-lis[1]>1:
    print('NO')
else:
    print('YES')