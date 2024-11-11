import math
n = int(input())
while(n):
    x = int(input())
    y = int(math.sqrt(x))
    if((y*y)==x):
        print((y-1)*2)
    elif((y*(y+1))>=x):
        print((y*2)-1)
    else:
        print(y*2)
        
    
    
    n-=1