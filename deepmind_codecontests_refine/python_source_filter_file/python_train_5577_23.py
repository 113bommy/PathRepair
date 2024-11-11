n, a, b, c = map(int,input().split())
k = 4-n
if k == 0:
    print(0)
elif k == 1:
    print(min(a, 3*c, b+c))
elif k == 2:
    print(min(2*a, b, 2*c))
elif k == 3:
    print(min(3*a, a+b ,c))