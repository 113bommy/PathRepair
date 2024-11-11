l,r,x,y,k = map(int,input().split())
a11 = k*x
a12 = k*y
flag = 0

if a12 < l or r < a11:
    print('NO')
    flag += 1
d = 0
if flag == 0 and a12 >= l:
    for i in range(l,min(int(a12)+1,r+1)):
        if i % k == 0:
            print('YES')
            flag += 1
            break
    d += 1

if flag == 0 and a11 <= r:
    for i in range(max(int(a11),l),min(r+1, int(a12)+1)):
        if i % k == 0:
            print('YES')
            flag += 1
            break
    d += 1

if flag == 0 and d == 2:
    print('NO')