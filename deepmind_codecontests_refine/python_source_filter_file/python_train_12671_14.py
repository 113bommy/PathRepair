l,r,x,y=list(map(int,input().split()))

if y%x!=0:
    print(0)
else:    
    k=y//x
    l//=x
    r//=x
    i=1
    s=0
    
    import math
    while i*i<=k:
        if k%i==0:
            
            if l<=i and i<=r:
                if l<=k//i and k//i<=r and math.gcd(i,k//i)==1:
                    if i==k//i:
                        s+=1
                    else:
                        s+=2
        i+=1
    
    
    print(s)