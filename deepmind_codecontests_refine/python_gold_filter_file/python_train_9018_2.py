x,y=map(int,input().split())
if x==0 and y==1:
    print("yes")
elif y==1:
    print("no")
else:
    if x+2>y and (x-y+1)%2==0 and y>0 and x>=y-1:
        print("yes")
    else:
        print("no")
