x,y=input().split()
x=int(x)
y=int(y)
if y==0 and x>=0:
    print("No")
elif x==y-1:
    print("Yes")
elif x==y:
    print("Yes")
elif y==1 and x>0:
    print("No")
elif x>y:
    cc=y-1
    if (x-cc)%2==0:
        print("Yes")
    else:
        print("No")
elif x<y-1:
    print("No")