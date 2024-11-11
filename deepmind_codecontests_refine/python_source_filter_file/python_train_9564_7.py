lis=[]
for i in range(10):
  lis.append(input())
 
for i in sorted(lis,reverse=True)[:3]:
  print(i)