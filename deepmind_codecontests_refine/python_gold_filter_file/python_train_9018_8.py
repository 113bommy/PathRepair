x,y=map(int,input().split())
a=1
b=0
if y==0 or (y==1 and x>0):
    print("No")
    exit()
else:
    a=a+a*(y-1)
    b=b+y-1
 
    x=x-b
    print("Yes") if x%2==0 and x>=0 else print("No")