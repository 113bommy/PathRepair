from bisect import bisect_left
from bisect import bisect_right
for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    sums=[0]*(2*k+1)
    mini=[]
    maxi=[]
    for i in range(n//2):
        sumi=a[i]+a[n-i-1]
        sums[sumi]+=1
        mini.append(min(a[i],a[n-i-1]))
        maxi.append(max(a[i],a[n-i-1]))
    mini.sort()
    maxi.sort()
    minti=100000000000000
    for x in range(2,2*k+1):
        #find first position where x-k occurs:
        mnpos=n//2-bisect_left(mini,x-1)
        mxpos=bisect_left(maxi,x-k)
        c2=mnpos+mxpos
        c1=n//2-sums[x]-c2
        minti=min(minti,c1+c2*2)
        #print(mnpos,mxpos,minti)
    print(minti)
        
        
        
