n=int(input())
a=0
for i in range(n):
  if int(input())%2==1:
    print("first")
    a=1
  break
if a==0:
  print("second")