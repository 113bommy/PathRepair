t = int(input())
for _ in range(t):
    n = int(input())
    array = list(map(int, input().split()))
    one = sum(array)
    zero = n-one
    x=11
    if n == x:
        print(int(x/2))
        print('10'*int(x/2))
    if zero <= one:
        if one % 2 == 0:
            print(one)
            ans = '1 '*(one)
            print(ans[:-1])
        else:
            print(one-1)
            ans = '1 '*(one-1)
            print(ans[:-1])
    else:
        print(zero)
        ans = '0 '*(zero)
        print(ans[:-1])