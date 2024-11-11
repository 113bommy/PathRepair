fact_list=[None]*300001
inv_fact_list=[None]*300001
fact_list[0]=1
inv_fact_list[0]=1
"""
def inv(n):
    if inv_fact_list[n]!=None:
        return inv_fact_list[n]
    m=fact_list[n]
    s=1
    for i in range(30):
        if i!=23 and i!=26:
            s=(s*m)%998244353
        m=(m**2)%998244353
    inv_fact_list[n]=s
    return s
def enc(n):
    if n==0:
        return "("
    s=""
    while n>0:
        s+=chr(n%86+40)
        n//=86
    return s
 
def dec(s):
    n=0
    for i in range(len(s)):
        n+=(86**i)*(ord(s[i])-40)
    return n
"""
def comb(n,r):
    if r==0 or r==n:
        return 1
    if r==1 or r==n-1:
        return n
    if inv_fact_list[n-r]!=None:
        invnr=inv_fact_list[n-r]
    else:
        m=fact_list[n-r]
        invnr=1
        for i in range(30):
            if i!=23 and i!=26:
                invnr=(invnr*m)%998244353
            m=(m**2)%998244353
        inv_fact_list[n-r]=invnr
    if inv_fact_list[r]!=None:
        invr=inv_fact_list[r]
    else:
        m=fact_list[r]
        invr=1
        for i in range(30):
            if i!=23 and i!=26:
                invr=(invr*m)%998244353
            m=(m**2)%998244353
        inv_fact_list[r]=invr
    return (((fact_list[n]*invnr)%998244353)*invr)%998244353
 
for i in range(1,300001):
    fact_list[i]=(fact_list[i-1]*i)%998244353
 
s=input().split()
n,a,b,k=int(s[0]),int(s[1]),int(s[2]),int(s[3])
res=0
for i in range(n+1):
    if k-a*i<0:
        break
    if (k-a*i)%b==0 and 0<=(k-a*i)//b<=n:
        res=(res+comb(n,i)*comb(n,(k-a*i)//b))%998244353
print(res)