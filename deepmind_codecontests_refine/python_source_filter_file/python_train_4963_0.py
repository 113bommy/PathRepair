def p(n,k) :
    k1=0
    k2=0
    while (n>0):
        k1+=min(n,k)
        n-=min(n,k)
        k2+=n//10
        n-=n//10
    if k1>k2 :
        return True
    else :
        return False
        

n=int(input())
p1=1
ost=n
while (p1<=ost) :
    mid=(p1+ost)//2
    if p(n,mid):
        ost=mid-1
    else :
        p1=mid+1
print(p1)

