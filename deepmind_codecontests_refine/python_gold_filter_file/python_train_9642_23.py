n=int(input())
a = str(input())
r = list(a)
if r[0] == 'S' and r[n-1] == 'F':
    print('YES')
else:
    print('NO')
