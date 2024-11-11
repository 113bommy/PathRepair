n,k,s = [int(x) for x in input().split()]
if n == 2:
    if s != k:
        print('NO')
    else:
        print('YES')
        if k%2 == 1:
            print('2 1 '*(k//2)+'2')
        else:
            print('2 1 '*(k//2))
else:
    if k > s:
        print('NO')
    elif k*(n-1) < s:
        print('NO')
    else:
        print('YES')
        q = (s-k)//(n-2)
        r = (s-k)%(n-2)
        for i in range(q):
            if i%2 == 0:
                print(n, end = ' ')
            else:
                print(1, end = ' ')
        normal = q%2 == 0
        if k-q == 1:
            if normal:
                print(r+2)
            else:
                print(n-r-1)
        elif k-q > 1:
            if normal:
                print(r+2, end = ' ')
                if (k-q-1)% 2 == 0:
                    print((str(r+1)+' '+str(r+2)+' ')*((k-q-1)//2))
                else:
                    print((str(r+1)+' '+str(r+2)+' ')*((k-q-1)//2)+str(r+1))
                    
            else:
                print(n-r-1, end = ' ')
                last = n-r-1
                if (k-q-1)% 2 == 0:
                    print((str(n-r)+' '+str(n-r-1)+' ')*((k-q-1)//2))
                else:
                    print((str(n-r)+' '+str(n-r-1)+' ')*((k-q-1)//2)+str(n-r))