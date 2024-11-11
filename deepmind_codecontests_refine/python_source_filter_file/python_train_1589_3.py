t=int(input())
for i in range(t):
    x,y,n=[int(h) for h in input().split()]
    a=n-n%x+y
    b=n-n%x
    if a>n:
        print(b)
    else:
        print(a)