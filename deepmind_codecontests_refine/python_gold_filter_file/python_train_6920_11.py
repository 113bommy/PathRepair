n,m=map(int,input().split())
c=0
while(n>0 and m>0):
    if (n!=0 or m!=0) and (n>=2 or m>=2):
        if n>m:
            n-=2
            m-=1
            c+=1
        else:
            
            m-=2
            n-=1
            c+=1
    else:
        break
#print(n,m)
print(c)    
            
        
        
                
                
        
        
        
                
        
        
       
        
            
                
            
                