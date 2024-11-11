import math
for _ in range(int(input())):
    
    a1,b1 = map(int,input().split())
    a2,b2 = map(int,input().split())
    
    summ = min(a1,b1) + min(a2,b2)
    
    if summ==max(a1,b1) and summ==max(a2,b2):
        print('Yes')
        
    else:
        print('No')