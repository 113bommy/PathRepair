def g(A,l,m,r):
 global c
 L,R=A[l:m]+[1e9],A[m:r]+[1e9]
 i=j=0
 for k in range(l,r):
  if L[i]<R[j]:A[k]=L[i];i+=1
  else:A[k]=R[j];j+=1;c+=m-l-i
 return c
def s(A,l,r):
 if l+1<r:
  m=(l+r)//2
  return s(A,l,m)+s(A,m,r)+g(A,l,m,r)
 else:return 0
c=0
n=int(input())
A=list(map(int,input().split()))
print(c)
