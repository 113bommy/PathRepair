n = int(input())
a1,a2 = [int(i) for i in input().split()]
b1,b2 = [int(i) for i in input().split()]
c1,c2 = [int(i) for i in input().split()]
if c1 == a1+1 and c2 == a2 or c1 ==a1-1 and c2==a2 or c1 == a1-1 and c2 == a2+1 or c1 == a1-1 and c2 == a2-1 or c1 == a1+1 and c2 == a2+1 or c1 == a1+1 and c2 == a2-1 or c1 == a1 and c2 == a2+1 or c1 == a1 and c2 == a2-1:
    print('NO')
elif c2 == a2 or c1 == a1:
    print('NO')
else:
    if b1 < a1 and c1<a1 and c2 > a2 and b2 > a1:
        print('YES')
        exit()
    if b1 < a1 and c1<a1 and c2 < a2 and b2 < a1:
        print('YES')
        exit()
    if b1 > a1 and c1>a1 and c2 > a2 and b2 > a1:
        print('YES')
        exit()
    if b1 > a1 and c1>a1 and c2 < a2 and b2 < a1:
        print('YES')
        exit()
    print('NO')