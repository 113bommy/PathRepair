n,a,b,c = map(int,input().split())
if n%4 == 0:
    print(0)
else:
    k = 4 - n%4
    if k == 1:
        print(min(a,3*c,1*c+1*b,))
    elif k == 2:
        print(min(b,2*a,2*c))
    elif k == 3:
        print(min(3*a,c,b+a))