n=int(input())
t=n%4
if n==0:
    print(0)
else:
    if t==0:
        print(6)
    elif t==1:
        print(8)
    elif t==2:
        print(4)
    elif t==3:
        print(2)