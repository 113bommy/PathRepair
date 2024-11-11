t=int(input())
while t>0:
    n=int(input())
    if(n==3):
        print("Yes")
    else:
        if(n%2==0):
            print("Yes")
        else:
            print("No")
    t-=1