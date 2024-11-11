n, a, b, c = [int(i) for i in input().split()]

k = (4 - n%4)%4

if k == 0:
    print(0)
elif k == 1:
    print(min([a, b+c, 3*c]))
elif k == 2:
    print(min([2*a, b]))
elif k == 3:
    print(min([3*a, a + b, c]))