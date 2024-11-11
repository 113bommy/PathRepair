a=int(input())
i=a+1
u=i
while(int(u)>=a and i<=9000):
    u=str(i)
    f=list(u)
    x=f.count(f[0])
    y=f.count(f[1])
    z=f.count(f[2])
    i=i+1
    if(x==1 and y==1 and z==1):
        print(u)
        break
    
    