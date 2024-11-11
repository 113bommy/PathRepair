import sys
cin = int(sys.stdin.readline().strip())
for testcase in range(cin):
    n,m,k = sys.stdin.readline().strip().split()
    n = int(n)
    m = int(m)
    k = int(k)
    if n%2 == 0 and m%2 == 0:
        if k%2 == 1:
            print('NO')
        else:
            print('Yes')
    elif n%2 == 0 and m%2 == 1:
        if k%2 == 1:
            print('NO')
        else:
            if k*2 <= n*(m-1):
                print('Yes')
            else:
                print('No')
    else:
        if k >= m//2 and (k-m//2)%2 == 0 and (m)*(n-1) >= (k-m//2)*2:
            print('Yes')
        else:
            print('No')
