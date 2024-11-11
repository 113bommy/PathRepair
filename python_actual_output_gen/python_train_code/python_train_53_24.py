try:
    s=input()
    k=[]
    
    for i in range(len(s)):
        
        if(s[i]=='+'):
            continue
            
        else:
            k.append(s[i])
            
            
            
    
    k.sort()
    j=[]
    for i in range(len(k)):
        j.append(k[i])
        j.append('+')
    j.pop(-1)    
    print(*j)
    
    
except:
    pass
