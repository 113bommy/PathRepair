x,y=list(map(int,input().split()))
if 2*(x+1)<y:
    print(-1)
    exit(0)
if x+1>y:
    print(-1)
    exit(0)
if x==y+1:
    print("0"+"10"*y)
if x==y:
    print("01"*y)
elif 2*x>y:
    t=y-x
    print("110"*t+"10"*(x-t))
elif 2*x==y:
    print("110"*x)
else:
    t=y-2*x
    print("110"*x+"1"*t)