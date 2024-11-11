n=int(input())
a=[int(x) for x in input().split()]
b=0
for i in a:
  b=b^a
if b==0:
  print("Yes")
else:
  print("No")