def break_test(n, k):
    '''
    http://codeforces.com/problemset/problem/311/A

    Params:
    n: int -- 2<=n<=2000 number of points we have to generate
    k: int -- 1<=k<=10^9 min number of comparisons breaking the program

    Return:
    a b : int int -- n lines with braeking points x and y
    OR
    'no solution'

    tot:
    2 .. n => n-1
    3 .. n => n-2
    ..
    n .. n => 1
    no solution: k > (n-1)*n/2

    proposition:
    0 0
    1 0
    2 0
    ..
    n 0
    '''
    if k > n * (n-1) / 2:
        print('no solution')
    else:
        for i in range(n):
            print('{} {}'.format(i, 0))

n, k = input().split(' ')
break_test(int(n), int(k))
