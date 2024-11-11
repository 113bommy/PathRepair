import math
for _ in range(int(input())):
    
    a1,b1 = map(int,input().split())
    a2,b2 = map(int,input().split())
    
    sum = min(a1,b1) + min(a1,b2)
    
    if sum==max(a1,b1) and sum==max(a2,b2):
        print('Yes')
        
    else:
        print('No')