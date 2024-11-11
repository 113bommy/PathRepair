n = int(input())
 
for i in range(n):
    
    h,m = map(int,input().split())
    
    done = False
    
    while not done: 
    
        x = 60 - m
        y = 24 - h - 1
           
        print(x + (y * 60))
        break

            