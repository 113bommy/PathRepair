n = int(input())
a = [int(x) for x in input().split()]
ans = ''
c = 0
num = 0
if n == 1:
    print('YES')
else:
    for i in range(n):
        b = a.count(a[i])
        if(b>c):
            c = b
            num = a[i]
    c1 = 0
    for i in range(n):
        if a[i] != num:
            c1 += 1
    if c <= c1:
        print('YES')
    else:
        print('NO')





