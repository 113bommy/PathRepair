
n = int(input())

a = list(map(int,input().split()))
flag = 1

ind = a.index(max(a))

for i in range(1,len(a)-1) :
    
    if a[i]<a[i+1] and a[i]<a[i-1] :
        
        print("N0")
        
        flag = 0 
        
        break 
if flag ==1 :
    
    asc = a[:ind] 
    
    temp1 = sorted(asc)
    
    if asc==temp1 :
        
        dsc = a[ind+1:]
        
        temp2 = sorted(dsc,reverse=True)
        
        if dsc==temp2 :
            
            print("YES")
            
        else :
            
            print("NO")
            
    else :
        
        print("NO")
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    