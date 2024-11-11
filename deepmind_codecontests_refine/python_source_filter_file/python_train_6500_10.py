
n=input()
cost=list(map(int,input().split()))
cost2=sorted(cost)
for i in range(1,len(cost)):
  cost[i]+=cost[i-1]
  cost2[i]+=cost2[i-1]
print (cost)
print(cost2)
for _ in range(int(input())):
  typee,l,r=map(int,input().split())
  if   l!=1:
    if typee==1:
      print(cost[r-1]-cost[abs(l-2)])
    else:
      print(cost2[r-1]-cost2[abs(l-2)])
  else:
    if typee==1:
      print(cost[r-1])
    else:
      print(cost2[r-1])