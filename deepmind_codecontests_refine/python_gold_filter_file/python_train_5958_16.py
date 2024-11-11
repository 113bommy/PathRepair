import math
for _ in range(int(input())):
    n,g,b=map(int,input().strip().split(" "))
    if g>=b or n<=g: print(n)
    else:
        k=(n+1)//2
        m=math.ceil(k/g)
        print(max(n,m*b-b+k))
    
    
    
