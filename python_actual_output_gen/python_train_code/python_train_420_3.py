n, m = map(int, input().split())

if n - m == 1:
    print('0'+'10'*m)
elif n-m>1:
    print(-1)
else:
    if 2*n - m >=0:
        print('110'*(m-n)+'10'*(2*n-m))
    elif - 2 <= 2*n - m <= -1:
        print('110'*(m-n-1) + '1' * (m - 2 * n))
    else:
        print(-1)
