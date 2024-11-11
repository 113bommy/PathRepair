import math
for _ in range(int(input())):
    n=int(input())
    FF="FastestFinger"
    A="Ashishgup"
    if(n==1):
        print(FF)
    elif(n==2):
        print(A)
    elif(n%2==1):
        print(A)
    elif(n%2==0):
        temp=n
        i=0
        while(True):
            if(temp%2==0):
                temp=temp//2
            else:
                break
            i+=1
        if(i==1):
            x=0
            for j in range(3,int((n//2)**.5)+1):
                if((n//2)%i==0):
                    print(A)
                    x=1
                    break
                    
            if(x==0):
                print(FF)
            
        else:    
            if(temp==1):
                print(FF)
            else:
                print(A)