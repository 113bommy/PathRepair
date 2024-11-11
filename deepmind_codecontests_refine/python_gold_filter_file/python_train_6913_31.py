

a,b=map(int,input().split())
if(b==0 and a==1):
    print(0)
elif(b>0):
    f=pow(10,a-1)
    d=b*f
    print(d)
else:
    print("No solution")
