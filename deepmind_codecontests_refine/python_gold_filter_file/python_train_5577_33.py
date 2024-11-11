n,a,b,c=(int(i) for i in input().split())
if(n%4==0):
    print(0)
else:
    if(n%4==3):
        print(min(a,3*c,b+c))
    elif(n%4==2):
        print(min(b,2*a,2*c))
    else:
        print(min(c,3*a,a+b))