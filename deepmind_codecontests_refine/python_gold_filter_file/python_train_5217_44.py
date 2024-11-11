n=int(input())
if n<=10:
    print(0)
else:
    n=n-10
    if n==15 or n>11:
        print(0)
    elif n==10:
        print(15)
    else:
        print(4)