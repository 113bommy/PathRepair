x,y=map(int,input().split())
if y==0:
    print("No")
elif y==1 and x>=y:
    print("No")
elif x==0 and y!=1:
    print("No")
elif y%2==0:
    if (x>=y-1):
        if x%2!=0:
            print("Yes")
        else:
            print("No")
    else:
        print("No")
elif y%2!=0:
    if (x>=y-1):
        if x%2==0:
            print("Yes")
        else:
            print("No")
    else:
        print("No")
        

