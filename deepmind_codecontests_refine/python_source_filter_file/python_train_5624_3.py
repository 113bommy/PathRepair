def search(X,Y):

 n=len(X)
 m=len(Y)
 p=[i for i in range(m+1)]
 for i in range(n):
  q=list(range(m+1))
  q[0] = i+1
  for j in range(m):
   if X[i]==Y[j]:
    cost=0
   else:
    cost=1
   q[j+1]=min(p[j+1]+1,q[j]+1,p[j]+cost)
  p,q=q,p
 
 return pre[m]


X=input()
Y=input()

print(search(X,Y))

