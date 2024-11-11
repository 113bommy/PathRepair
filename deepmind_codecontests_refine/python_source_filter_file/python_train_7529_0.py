n=int(input())
x=[]
s=0
for i in range(n):
    x.append(list(map(int,input().split())))
for i in range(n):
    if i!=n//2:
        s+=x[i][i]
        s+=x[n//2][i]
        s+=x[i][n//2]
        s+x[i][n-i-1]
s+=x[n//2][n//2]
print(s)
    
        
    
    




        
            
        
            
    
    
            
    
        

    
