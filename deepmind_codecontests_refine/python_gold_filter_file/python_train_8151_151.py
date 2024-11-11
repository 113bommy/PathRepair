# cook your dish here
try:
    import math
    n, k, l, c, d, p, nl, np=map(int,input().split())
    a=min(math.floor(k*l /nl) ,c*d,math.floor(p/np))/n
    print(math.floor(a))
    
    
        
except:
    pass