[a,b]=map(int,input().split())
x=a-b
if x<0:
    x=b-a
    c=x//2
    z=(str(a)+" " +str(c))
else:
    c=x//2
    z=(str(b)+" "+str(c))
    print(z)