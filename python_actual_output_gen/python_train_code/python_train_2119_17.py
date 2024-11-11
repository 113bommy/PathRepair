d,n=[int(x) for x in input().split()]
counter=int(input())
for item in range(counter):
    a,b=[int(x) for x in input().split()]
    if a<=d:
        if abs(a-n)<=b<=d-abs(d-n):
            print('YES')
        else:
            print('NO')
    else:
        print('NO')
