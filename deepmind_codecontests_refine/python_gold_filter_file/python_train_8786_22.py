def find_group(least,more,a,m):
    hold = 0
    i = 0
    while i < m and hold <= more:
        if hold < least:
            hold += a[i]
            i += 1
        elif sum(a[i:]) < least:
            return 0
        elif sum(a[i:]) > more:
            hold += a[i]
            i += 1
        else :
            return i + 1

    return 0
            


m = int(input())
a = list(map(int,input().split()))
least,more = list(map(int,input().split()))

print (find_group(least,more,a,m))
        
        
        
    
    
            
        
            

    
        


          
          
          
     
