def g(A,l,m,r):
 global c
 L=A[l:m]+[1e10]
 R=A[m:r]+[1e10]
 i=j=0
 for k in range(l,r):
  if L[i]<R[j]:A[k]=L[i];i+=1
  else:A[k]=R[j];j+=1
  c+=1
def s(A,l,r):
 if l+1<r:
  m=(l+r)//2
  s(A,l,m)
  s(A,m,r)
  g(A,l,m,r)
c=0
n=int(input())
A=list(map(int,input().split()))
s(A,0,n)
print(*A)
