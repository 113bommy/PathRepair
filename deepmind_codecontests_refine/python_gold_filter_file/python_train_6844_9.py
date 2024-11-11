n,k=map(int,input().split(" "))
l=list(map(int,input().split()))
ct=0
ctr=1
l3=[l[0]]
l2=l[:]
l2.sort()
#print(l,l2,l3)
f=[0]*101
for i in l2:
  f[i]+=1
for i in range(101):
  if f[i]>0:
    ct+=1
#print(ct)
if ct>=k:
  print("YES")
  print("1", end=" ")
  for i in range(1,n):
    if l[i] not in l3:
      print(i+1, end=" ")
      l3.append(l[i])
      ctr+=1
      if ctr==k:
        break
  #print(l3)
else:
  print("NO")