#binary exponentiaton
def pow(n,p):
    ans=1
    
    while(p>0):
        if(p&1):
            ans*=n
        n*=n
        p>>=1
    return ans
n=int(input())
s=0
m=0
if n-3>=0:
    s=2*4*3*pow(4,n-3)
if n-4>=0:
    m=4*3*3*pow(4,n-4)
print(s+m)
        