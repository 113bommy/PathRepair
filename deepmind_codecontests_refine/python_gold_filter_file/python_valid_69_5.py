import math

t=int(input())
for _ in range(t):
    n = input()
    len_ = len(n)
    i = 1
    a = []
    while(i<=2**100):
        a.append(str(i))
        i = i*2
    ans = 100
    for i in range(len(a)):
        count = 0
        k = 0
        l = 0
        while(l<len(n) and k<len(a[i])):
            if n[l] == a[i][k]:
                count = count + 1
                k = k+1
            l = l+1
        
        ans = min(ans,len_ + len(a[i]) - 2*count)
    # print(len(a))
    print(ans)
        
            
        
                
                    
            
            
            
            
    
        
        
        
    
    
   
    
    
    
   
    
        
    
   
