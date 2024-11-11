n, a, b, c = map(int, input().split())
k = n%4
if k == 0:
    print(0)
elif k == 3:
    print(min(a, 3*c, b+c))
elif k == 2:
    print(min(2*a, b, 2*c))
elif k == 1:
    print(min(3*a, a+b ,c))