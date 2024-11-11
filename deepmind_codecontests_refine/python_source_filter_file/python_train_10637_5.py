n=int(input())
A=[int(i) for i in input().split()]
k=len(str(A[0]))
mod=998244353
ans=0
for i in range(n):
  for j in range(k):
    a=int(str(A[i])[j])
    ans+=10**(2*(k-j)-1)*a*n
    ans+=10**(2*(k-j)-2)*a*n
    ans%=mod
a=str(A[0])
nn=len(a)
ans1=0
for i in range(nn):
  ans1+=int(a[i])*10**(2*(nn-i)-1)
  ans1+=int(a[i])*10**(2*(nn-i)-2)
print(ans1 if n==1 else ans)