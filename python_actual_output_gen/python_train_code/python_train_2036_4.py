k=int(input())
liste=list(map(int,input().split()))
x=0
y=0
list1=[0]
for i in liste:
  if i>0:
    x+=i
if x%2:
  print(x)
else:
  for i in liste:
    if i%2:
      list1.append(abs(i))
print(x-min (list1))