import math
  
  
    
for _ in range(int(input())):
    n,x=map(int,input().split())
    if n<=2:
        print(n)
    else:
        n-=2
        print(1+math.ceil(n/x))
    
