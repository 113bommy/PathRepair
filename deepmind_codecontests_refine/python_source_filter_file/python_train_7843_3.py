def ok(n,q):
    countn,countq=[0]*10,[0]*10
    while n>0:
        countn[n%10]=1
        n//=10
    while q>0:
        countq[q%10]=1
        q//=10
    for i in range(10):
        if countn[i]==countq[i] and countn[i]>0:
            return True
    return False
n=int(input())
ans=0
sq=int((n+0.5)**0.5)
for i in range(1,sq+5):
    if n%i==0 and n//i!=i:
        if ok(i,n):
            ans+=1
        if ok(n//i,n):
            ans+=1
    if n%i==0 and n//i==i:
        if ok(i,n):
            ans+=1
print(ans)