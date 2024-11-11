n, k = map(int, input().split())

if k % 2:
    print("YES")
    print('.' * n)

    a = min(n-2, k)
    print('.' + ('#' * a).center(n-2, '.') + '.')
    k -= a

    if k == 0:
        print('.' * n)
    else:
        print('.' + '#' * (k-1) + '.' * (n - 2 - k) + '#' + '.')

    print('.' * n)
else:
    print('YES')
    print('.' * n)
    a = k // 2
    for i in range(2):
        print('.' + '#' * a + '.' * (n - 1 - a))
    print('.' * n)
