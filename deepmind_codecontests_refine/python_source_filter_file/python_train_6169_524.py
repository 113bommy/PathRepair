t=int(input())
while t>0:
    n=int(input())
    if(n==3):
        print("YES")
    else:
        if(n%4==0):
            print("YES")
        else:
            print("NO")
    t-=1