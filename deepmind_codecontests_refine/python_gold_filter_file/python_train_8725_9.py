n,k=map(int,input().split())
q=n//k
r=n%k
if k%2==1:
    print(q**3)
elif(q*k+k//2<=n):
    print(q**3+(q+1)**3)
else:
    print(q**3+q**3)