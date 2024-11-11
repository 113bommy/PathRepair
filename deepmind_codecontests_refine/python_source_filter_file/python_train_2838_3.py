#import sys
#import math
#sys.stdout=open("python/output.txt","w")
#sys.stdin=open("python/input.txt","r")
t=int(input())
for i in range(t):
    x,y,z=map(int,input().split())
    c=1
    if x!=y and y!=z and x!=z:
        print("NO")
    else:
        if x==y and z<=x:
            print("YES")
            print(x,x,x)
        elif y==z and x<=y:
            print("YES")
            print(y,y,y)
        elif x==z and y<=x:
            print("YES")
            print(z,z,z)
        else:
            print("NO")
         
        
        
    
    
    
    