k = 0
n = int(input())
s = list(input())
a = list(set(s))
for i in a:
  if s.count(i)>1:
    k+=1
if not(k>0) and (n>1):
  print("No")
else: 
  print("Yes")