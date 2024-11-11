import sys
def t(A,p,r):
 x=A[r][1];i=p-1
 for j in range(p,r):
  if A[j][1]<=x:i+=1;A[i],A[j]=A[j],A[i]
 A[i+1],A[r]=A[r],A[i+1]
 return i+1
def k(A,p,r):
 if p<r:q=t(A,p,r);k(A,p,q-1);k(A,q+1,r)
def s(A):
 for i in range(n-1):
  if A[i][1]==A[i+1][1]:
   if A[i][2]>A[i+1][2]:return 0
 return 1
n=int(input())
f=lambda x,i:(x[0],int(x[1]),i)
A=[f(sys.stdin.readline().split(),i))for i in range(n)]
k(A,0,n-1)
print(['Not s','S'][s(A)]+'table')
for e in A:print(*e[:2])
