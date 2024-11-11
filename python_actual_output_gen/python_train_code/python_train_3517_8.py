t = int(input(''))
for _ in range(t):
    a = input('').split(' ')
    x = int(a[0])
    k = int(a[1])
    if(x+k % 2 == 1):
        print('NO')
        continue
    q = (x+k)
    if(k*(k+1) > q):
        print('NO')
    else:
        print('YES')