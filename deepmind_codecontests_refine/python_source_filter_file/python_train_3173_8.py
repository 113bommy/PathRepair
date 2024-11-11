import math
n,m = map(int,input().split())
x = [int(x) for x in input().split()]

l = min(x)/m
r = max(x)/m

if(abs(l-r)>m):
    print("NO")
else:
    print("YES")
    for i in x:
        
        c=0
        while(c<i):
            y=1
            while(y<=m and c<i):
                print(y,end=" ")
                y+=1
                c+=1
                
            
        print()
    
                
                
                
                
                
                
                
    