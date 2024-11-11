n=int(input())
x=int(input())
if x==2:
    n=n%6
    if n==0:
        print(2)
    elif n==1:
        print(1)
    elif n==2:
        print(0)
    elif n==3:
        print(0)
    elif n==4:
        print(1)
    else:
        print(1)
elif x==1:
    n=n%3
    if n==0:
        print(1)
    elif n==1:
        print(0)
    else:
        print(2)
else:
    n=n%6
    if n==0:
        print(0)
    elif n==1:
        print(1)
    elif n==2:
        print(1)
    elif n==3:
        print(2)
    elif n==4:
        print(2)
    else:
        print(0)
