y, k, n = map(int, input().split(' '))
r = n - y
rem = k - (y % k)
li = [rem for rem in range(rem, r, k)]
if not li:
    print('-1')
else:
    for x in li:
        print(x, end=' ')
