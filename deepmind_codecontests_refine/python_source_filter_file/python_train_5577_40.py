n,a,b,c=map(int,input().strip().split(" "))
if(n%4==1):
    y=min(3*a,a+b,c)
    print(y)
elif(n%4==2):
    y=min(2*a,b,2*c)
    print(y)
elif(n%4==0):
    print(0)
else:
    y=min(a,3*c)
    print(y)    
