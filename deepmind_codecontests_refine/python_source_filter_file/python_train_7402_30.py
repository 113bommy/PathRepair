n=int(input())
b=n//3
if n==3:
    print("1 1 1")
    exit()
if n%3==0 and n!=3:
    if b%3==0:
        print(b-1,b-1,b+2)
    if b%3==1:
        print(b,b,b)
    else:
        print(b,b,b)
elif n%3==1:
    if b%3==0:
        print(b-1,b+1,b+1)
    if b%3==1:
        print(b,b,b+1)
    else:
        print(b,b-1,b+2)
else:
    if b%3==0:
        print(b-1,b+1,b+2)
    if b%3==1:
        print(b,b+1,b+1)
    else:
        print(b,b+2,b)
