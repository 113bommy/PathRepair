R=range
def F(a,b):A=len(a);return[all([len(set([a[i+j],b[j],'?']))<3for j in R(min(A-i,len(b)))])for i in R(A)]+[1]
def Z(X):
 i,j,k=X;A,B,C=map(len,[S[t]for t in X]);q=1e5
 for l in R(A+1):
  if M[i][j][l]:
   for r in R(l,A+B+1):
    if(B<r-l or M[j][k][r-l])*M[i][k][min(A,r)]:q=min(q,max(A,l+B,r+C))
 return q
S=[input()for i in R(3)]
M=[[F(i,j)for j in S]for i in S]
from itertools import*;print(min([Z(i)for i in permutations(R(3))]))