n=int(input())
A=list(map(int,input().split()))
Amax=max(A)
Amin=min(A)
ans=0
B=[]
if Amin>=0:
    ans=n-1
    for i in range(n-1):
        B.append([i+1,i+2])
elif Amax<=0:
    ans=n-1
    for i in range(n-1):
        B.append([n-i,n-i-1])
elif Amax>=-Amin:
    a=A.index(Amax)
    for i in range(n):
        if A[i]!=a:
            ans+=1
            B.append([a+1,i+1])
    for i in range(n-1):
        ans+=1
        B.append([i+1,i+2])
else:
    a=A.index(Amin)
    for i in range(n):
        if A[i]!=a:
            ans+=1
            B.append([a+1,i+1])
    for i in range(n-1):
        ans+=1
        B.append([n-i,n-i-1])
print(ans)
for b in B:
    print(' '.join(map(str,b)))