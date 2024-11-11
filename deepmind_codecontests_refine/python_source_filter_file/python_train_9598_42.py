(n,a,b)=map(int,input().split())
x=n-a-b
if(x==0):
    print(b)
if(x<0):
    print(n-b)
if(x>0):
    print(b)
