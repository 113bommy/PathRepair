l,r,a = map(int,input().split())
if(l==r):
    print(l+r+2*(a//2))
else:
    k = min(l,r)
    j = max(l,r)
    while(k!=j and a!=0):
        k+=1
        a-=1
    print(2*k)