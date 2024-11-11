test_cases=int(input())
res=[]
for i in range(0,test_cases):
  no_of_places=int(input())
  a=list(map(int,input().split(" ")));
  equal=True
  for i in range(0,no_of_places-1):
    if a[i]!=a[i+1]:
      equal=False
      break
 # print("a")
  if equal==True:
    res.append(-1);
    #print(-1)
  else:
    #print("number")
    max=a[0]
    index=0
    for i in range(1,no_of_places):
      if a[i]>max:
        max=a[i]
    #print(max)
    for i in range(1,no_of_places-1):
      if a[i]== max and (a[i]!=a[i-1] or a[i]!=a[i+1]):
        #print(i)
        res.append(i+1)
        index=i

        break
    if index==0:
      if a[0]==max and a[0]>a[1]:
        res.append(1)
      elif a[no_of_places-1]==max and a[no_of_places-1]>a[no_of_places-2]:
        res.append(no_of_places)
      else:
        res.append(-1)
for i in res:
  print(i)
