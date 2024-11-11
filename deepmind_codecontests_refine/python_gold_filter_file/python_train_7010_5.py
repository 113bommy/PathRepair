n,m = map(int,input().split())

if n == 0 and m >= 1:
    print('Impossible')
elif n == 0 and m == 0:
    print(n,m)
elif n >= 1 and m >= 1:
    maxm = n + (m - 1)
    print(max(n,m),maxm)
elif n >= 1 and m == 0:
    print(n,n)