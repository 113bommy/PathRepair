def ask(X,Y):
 cost=[0]
 for j in Y:
  for i in range(len(cost)-1,-1,-1):
   a=X.find(c,cost[i])+1
   if a:
    if i+1<len(cost):
     cost[i+1]=min(cost[i+1],a)
    else:
     cost.append(a)
 return len(cost)-1
 


q=int(input())
Z=[]
for p in range(q):
 X=input()
 Y=input()
 z=ask(X,Y)
 Z.append(z)

for p in range(q):
 print(Z[p])

