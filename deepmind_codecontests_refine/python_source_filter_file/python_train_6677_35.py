# import os

t = int(input())

for _ in range(t):
    n,a,b = map(int,input().split())

    # a cost for 1   - 'b' cost for 2

    if  a <= b:
        print(n*a)
    else:
        if n % 2 == 0:
            print((n//2)*b)
        else:
            print((n//2*b) + a)
        
    
    

    





 


# 04/01 - 21
# 05/01 - 27
# 06/01 - 28




    