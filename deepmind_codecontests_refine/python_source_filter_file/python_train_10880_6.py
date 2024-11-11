n=int(input())
a=n//4
b=n%4
if b%2==0 or a//4>=1 :
    if b==2 :
        print(a)
    else :
        print(a-1)
else :
    print(0)
    
