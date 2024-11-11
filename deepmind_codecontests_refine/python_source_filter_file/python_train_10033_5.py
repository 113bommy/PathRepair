def primefun(n):
    seive=[1 for i in range(n+1)]
    i=2
    while(i*i<=n+1):
        if seive[i]==1:
            for j in range(i*i,n+1,i):
                seive[j]=0
        i=i+1
    seive[0]=0
    seive[1]=0
    return seive
def AlmostPrime(n,sArray,c):
    f=0
    s=round(n**0.5)
    for j in range(2,s+1,1):
       if(n%j==0):
            if sArray[j]==1:
                f+=1
            if sArray[n//j]==1 and j!=(n//j):
                f+=1
    if f==2:
            
        c=c+1
    return c
            
f=0    
n=int(input())
sArray=primefun(n)
c=0
if n>=1 and n<6:
    print('0')
else:
    for i in range(6,n+1,1):
        c=AlmostPrime(i,sArray,c)
print(c)






















