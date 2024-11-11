x,y=map(int,input().split())
if y-1<=0:
    print("No")
elif x<y-1:
    print("No")
else:
    if (x-y+1)%2==0:
        print("Yes")
    else:
        print("No")
