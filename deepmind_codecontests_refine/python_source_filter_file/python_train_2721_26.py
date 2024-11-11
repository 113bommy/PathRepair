from math import ceil
a=int(input())
b=list(map(int, input().split()))
cnt=0
c=0
d=0
for i in b:
 
  if i<0:
    cnt+=1
  elif i>0:
    c+=1
  else:
    d+=1
if c>=ceil(len(b)/2):
  print("2")
elif d>=ceil(len(b)/2):
  print("0")
else:
  print("-1")
