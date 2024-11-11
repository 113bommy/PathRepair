s=int(input())
a=[]
while True:
  if s not in a:
    a.append(s)
  else:
    break
  if s%2==0:
    s/=2
  else:
    s=3*s+1
print(len(a))