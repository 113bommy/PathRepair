n=int(input())
if(n%3==0):
    a=1
    b=1
    n-=2
elif(n%3==1):
    a=1
    b=2
    n-=3
elif(n%3==2):
    a=1
    b=2
    n-=3


    
print(a,b,n)
