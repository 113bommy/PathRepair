def color_allcells (n,m,a):
    for x in range(n):
        for y in range(m):
            if a[x][y] == "1" :
                if y == 0 or y == m-1:
                    return 2
                elif x == 1 or x == n-1:
                    return 2
    return 4


n,m = list(map(int,input().split()))
a = []
for x in range(n):
    a.append(input().split())

print (color_allcells(n,m,a))

    
        
        
        
    
    
            
        
            

    
        


          
          
          
     
