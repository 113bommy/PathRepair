__author__ = 'zhan'

n = int(input())
candy = sorted([int(input()) for _ in range(n)])
ans = None

if n == 0:
    ans = [1, 1, 3, 3]
elif n == 4:
    a, b, c, d = candy
    if d == 3*a and b+c == 4*a:
        ans = []
elif n == 1:
    a = candy
    ans = [2*a, 2*a, 3*a]
elif n == 3:
    a, b, c = candy
    if c % 3 == 0 and 3*(a+b) == 4*c:
        ans = [c//3]
    elif 3*a == c:
        ans = [4*a-b]
    elif 4*a == b+c:
        ans = [3*a]
else:
    a, b = candy
    if b == 3*a:
        ans = [2*a, 2*a]
    elif b < 3*a:
        ans = [4*a-b, 3*a]

if ans is not None:
    print("YES")
    for x in ans:
        print(x)
else:
    print("NO")