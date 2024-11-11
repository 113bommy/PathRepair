l = [int(i) for i in input().split()]
n= l[0];m = l[1]
def socks(n,m):
    if n<m:
        return(0)
    elif n==m:
        return(1)
    else:
        e = n//m
        r = n%m
        return (n//m+socks(e+r,m))    


d =socks(n,m)

print (n+d)

    
    
    
    
  
