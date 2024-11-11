k = int(input())
a,b = map(int, input().split())
c = b//k
if c*k >= a:
    print('OK')
else:
    print('NO')