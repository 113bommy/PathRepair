import math
def power(n):
    z=0
    while n%2==0:
        n=n//2
        z+=1
    return z
for _ in range(int(input())):
    a,=map(int,input().split())
    if a==1 or a==4:
        print("FastestFinger")
    elif a==2:
        print("Ashishgup")
    
    elif a%2==1:
       print("Ashishgup")
    else:
        z=power(a)
        k=a//(2**z)
        if z>1:
            print("Ashishgup")
            
        
        else:
            for i in range(3,math.ceil(math.sqrt(a))+1,2):
                if a%i==0 and a//i>2:
                    
                    print("Ashishgup")
                    break
            else:
                print("FastestFinger")
 
