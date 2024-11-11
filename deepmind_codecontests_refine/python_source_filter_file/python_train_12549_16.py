n = int(input())
a = list(map(int, input().split()))
if n == 1:
    if a[0] == 1:
        print('YES')
    else:
        print('NO')
else:
    if sum(a[:-1]) >= n - 2:
        print('YES')
    else:
        print('NO')