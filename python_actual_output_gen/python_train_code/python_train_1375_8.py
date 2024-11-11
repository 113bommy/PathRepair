x=int(input())
if x==1:print(1)
else:
  ans=1
  w=[]
  for _ in range(1,x):w.append(input())
  for i in range(1,len(w)):
    if w[i-1]!=w[i]:
      ans+=1
  print(ans)
