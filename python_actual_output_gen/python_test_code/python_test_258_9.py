m=int(input())
count,flag=0,0
d=dict(zip(list(range(10)),list(range(10,0,-1))))
if str(m)[-2:]=='00': flag=1

if flag==1:
    count+=10
    m+=10
        
while m>=10:
    last=m%10
    if last == 0:
        m=m//10    
    else:    
        count+=d[last]
        m+=d[last]     
else:
    count+=d[m]+m-1
    print(count)
    
    
    


                

            
                
            
        
    
    
    
