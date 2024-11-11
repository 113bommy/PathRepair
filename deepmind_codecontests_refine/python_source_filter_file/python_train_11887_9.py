n = int(input())
l = [0 for i in range(2*n+1)]
if n%4 == 0:
    print('NO')
else:
    toggle = True
    for i in range(1,n+1):
        if toggle:
            l[i] = 2*i-1
            l[i+n] = 2*i
            toggle = False
        else:
            l[i] = 2*i
            l[i+n] = 2*i -1
            toggle = True
    print('YES')
    for i in range(1,2*n +1):
        print(l[i],end = " ")