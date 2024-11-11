n=int(input())
a=n//4
b=n%4
if n%2==0 or n//4>=1 :
    if b==2 :
        print(a)
    else :
        print(a-1)
else :
    print(0)
    
