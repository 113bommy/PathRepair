from math import gcd

l, r = map(int, input().split())
a = [i for i in range(l, r + 1)]
left = 0
right = r - l
if gcd(l, l + 1) != 1:
    print('NO')
else:
    print('YES')
    for i in range(0, r - l - 1, 2):
        print(a[i], a[i+1])
    print(a[r-l-1], a[r-l])