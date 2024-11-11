t = int(input())
def ans(a,b):
    
    
    if((a<1 or b<1)):
        return 0
    if(a==1 and b==1):
        return 1
    if(min(a,b)==abs(a-b)):
        return abs(a-b)
    if(min(a,b)<abs(a-b)):
        return min(a,b)
    else:
        diff = abs(a-b)
        p = min(a,b) - diff
        if(p==1 or p==0):
            return diff
        return abs(a-b) + int((2*p)/3)
    
        
        
        
        
        
    
for qq in range(t):
    
    a,b = map(int , input().split())
    print(ans(a,b))
    
        
    
    
    
    




