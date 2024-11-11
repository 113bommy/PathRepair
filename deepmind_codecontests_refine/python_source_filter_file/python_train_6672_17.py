
import sys
i=0
for _ in range(int(input())):
    if i==0:
        x,y=map(int,input().split())
        m=max(x,y)
        i+=1
        continue
    x,y=map(int,input().split())
    if max(x,y)<=m:
        m=max(x,y)
    elif min(x,y)<=m:
        m=min(x,y)
    else:
        print("NO")
        break

print("YES")
        
    
    
        
        
        
    