def gcd (p,q) :
    while p :
        p,q = q%p , p
    return (q)
I = lambda : map(int,input().split())
a , b = I()
a , b  = min(a,b) , max(a,b)
if b%a == 0 :
    exit(print("0"))
k1 = 0 
t = b-a
ans = 100
minn = 10**31
k=100
for i in range (1 , int (t**0.5) + 1 ) :
    if t%i == 0 :
        g = i
        k = (g - (a%g) )%g
        p = (a+k)*(b+k)//((gcd(a+k,b+k)))
        if p<minn :
             minn = p
             ans=k
        elif p==minn :
            ans = min(ans,k)
        g = t//i
        k = (g - (a%g) )%g
        p = (a+k)*(b+k)//((gcd(a+k,b+k)))
        if p<minn :
             minn = p
             ans=k
        elif p==minn :
            ans = min(ans,k)
print(ans)  
    
    
    
    