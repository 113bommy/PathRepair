import math
n=int(input())
arr=[int(item) for item in input().split()]
sumi=0
for j in arr:
    sumi=sumi+j
t=0
    
for i in range(n):
    t=t+arr[i]
    if(t>=math.ceil(sumi//2)):
        break
print(i+1)    
    

        
            
            
        
