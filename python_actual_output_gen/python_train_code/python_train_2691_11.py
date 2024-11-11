tests=int(input())
i = 1
while i < tests:
    angle=int(input())
    if 360%(180-angle) ==0:
        print('YES')
    else:
        print('NO')
    i+=1