


for _ in range(int(input())):
    
    x, y = map(int, input().split())
    
    c1, c2, c3, c4, c5, c6 = map(int, input().split())
    
    c2 = min(c2, c1 + c3)
    
    c3 = min(c3, c2 + c4)
    
    c4 = min(c4, c3 + c5)
    
    c5 = min(c5, c4 + c6)
    
    c6 = min(c6, c5 + c1)
    
    c1 = min(c1, c6 + c2)
    
    if x * y < 0:
        
        if x < 0:
            
            print(c3 * (-x) + c2 * y)
            
        else:
            
            print(c5 * x + c6 * (-y))
            
    else:
        
        if x + y > 0:
            
            if x > y:
                
                print(y * c1 + (x - y) * c6)
                
            else:
                
                print(x * c1 + (y - x) * c2)
                
        else:
            
            if x > y:
                
                print(-x * c4 + (x - y) * c5)
                
            else:
                
                print(-y * c4 + (y - x) * c3)