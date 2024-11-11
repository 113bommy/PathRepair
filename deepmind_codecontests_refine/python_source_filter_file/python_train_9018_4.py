x,y = (input().split())
x,y=int(x),int(y)
if y>=2 and (x+y)%2==1:print("Yes")
elif (x+y)%2==1:
    if y>x and y-x==1:print("Yes")
    else:print("No")
else:print("No")
    
