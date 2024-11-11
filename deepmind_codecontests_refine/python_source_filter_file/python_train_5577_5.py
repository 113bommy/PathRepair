n, a, b, c = map(int, input().split())
t  = n%4
if t!=0:
    t = 4 - t
if t == 0:
    print(0)
elif t == 1:
    print(min(a, b+c))
elif t==2:
    print(min(2*a, b, 2*c))
else:
    print(min(3*a, a+b, c))
