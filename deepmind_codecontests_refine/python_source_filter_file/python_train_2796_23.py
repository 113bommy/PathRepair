n,x = map(int,input().split())

if n == 2:
    if x == 2:
        print('Yes')
        print('\n'.join([1,2,3]))
    else:
        print('No')
else:
    if x == 1 or x == 2*n - 1:
        print('No')
    else:
        print('Yes')
        if x == 2:
            ans = list(range(3,2*n-2))
            ans = ans[:n-3] + [2*n - 1,1,2,2*n - 2] + ans[n-3:]
        else:
            ans = list(range(2*n - 1))
            ans = ans[3:x] + ans[x+1:2*n - 1]
            ans = ans[:n-3] + [1,2*n - 1,x,2] + ans[n-3:]
        print('\n'.join(str(i) for i in ans))
