n=int(input())
for i in range(n):
    angle=int(input())
    if 360/(180-angle) in range(int(360/angle)+1):
        print('YES')
    else:
        print('NO')