n,a,b,c=map(int,input().split())
if n%4==0:
    print(0)
    exit() 
    
rem=4-n%4 
#print(rem)
if rem==2:
    print(min(b,2*a,2*c))
elif rem==1:
    print(min(a,b+c,2*b+a,3*c))
elif rem==3:
    print(min(c,3*a,a+b,2*b+c,3*b+a))
    