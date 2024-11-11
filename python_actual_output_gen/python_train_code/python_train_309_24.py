

n,m,z = map(int,input().split())

ns = [i*n for i in range(1,z//n+1)]
ms = [i*m for i in range(1,z//n+1)]

cnt = 0

for i in ms :
    
    for j in ns :
        
        if j==i :
            
            cnt = cnt + 1 
            
        if j>i :
            
            break 
        
print(cnt)
        
        
    
    


    
    