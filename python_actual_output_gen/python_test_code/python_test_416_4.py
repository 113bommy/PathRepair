n=int(input())
a=list(map(int,input().split()))
def Sub(a,n):
    m = 1 
    l = 1 
    for i in range(1, n) : 
        if (a[i] > a[i-1]) : 
            l =l + 1 
        else :  
            if (m < l)  : 
                m == l    
            l = 1 
    if (m < l) : 
        m == l 
    return m 
print(Sub(a,n))        


