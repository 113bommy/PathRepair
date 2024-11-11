
a, b = map(int, input().split())

if b==0:
    print('NO')
elif b==1:
    if a==0:
        print('YES')
    else:
        print('NO')
else:
    # print(a-b+1)
    if (a-b+1)%2==0 and (a-b+1)>0:
        print('YES')
    else:
        print('NO')