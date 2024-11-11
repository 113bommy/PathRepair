n,p=map(int,input().split())
def factorize(n):
    f=[]
    p=2
    cnt=0
    while p**2<n:
        while n%p==0:
            cnt+=1
            n=n//p
        if cnt!=0:
            f.append([p,cnt])
            cnt=0
        p+=1
    if n!=1:
        f.append([n,1])
    return f

A=factorize(p)
ans=1
for i in range(len(A)):
    ans*=A[i][0]**(A[i][1]//n)
print(ans)