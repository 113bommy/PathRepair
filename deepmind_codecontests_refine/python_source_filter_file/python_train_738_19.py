import math
n=int(input())
if n%2==0:
    print(n//2)
else:
    i=3
    f=0
    c=0
    while(i<=int(math.ceil(math.sqrt(n)))):
        if n%i==0:
            c+=1
      
            n=n//i
            if n%2==0:
                f=1
                print(c+n//2)
                break
            else:
                i=3
        else:
            i+=1
    if f==0:
        print(c+1)
    
        