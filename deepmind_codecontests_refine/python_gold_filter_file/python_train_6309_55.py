n, k = map(int,input().split())
turns = n//k
if turns % 2 == 0:
    print('NO')
else:
    print('YES')