n = int(input())
for i in range(n):
    t = int(input())
    if 360%(180-t)==0: print('YES')
    else: print('NO')
