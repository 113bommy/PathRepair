def hcf(a,b):
    while(a%b!=0):
        rec=a//b
        a=b
        b=rec
    
    return b
    
    


n,m,d=list(map(int,input().split()))
maxi=max(m,n)
mini=min(m,n)
lcm=m*n/hcf(maxi,mini)
print(int(d//lcm))