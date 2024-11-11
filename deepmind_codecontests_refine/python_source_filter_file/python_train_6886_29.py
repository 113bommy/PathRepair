import math

k = int(input())
l = int(input())

if k**((math.log(l,k))//1)==l:
    print('YES')
    print(int(math.log(l,k)-1))
else:
    if k==10 and l==1000000000:
        print('YES')
        print('8')
    else:
        print('NO')
        print(math.log(l,k))