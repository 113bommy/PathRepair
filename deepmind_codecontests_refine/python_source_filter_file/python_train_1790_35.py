n=int(input())
for i in range(1,n):
    a=int(input())
    if (a%2==0) and (a>2):
        print(0)
    elif a==2:
        print(2)
    elif a==1:
        print(3)
    else:
        print(1)
