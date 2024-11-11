t=int(input())
while t>0:
    n=int(input())
    if(n==3):
        print("NO")
    else:
        if(n%4==0):
            print("YES")
        else:
            print("No")
    t-=1