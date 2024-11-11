n = int(input())
a = [0 for i in range(2*n)]
if n % 2 == 0:
    print('NO')
else:
    for i in range(n):
        k = 2*i+1
        if i % 2 == 0:
            a[i] = k
            a[n+i] = k+1
        else:
            a[i] = k+1
            a[n+i] = k
    print('YES')
    print(' '.join([str(i) for i in a]))