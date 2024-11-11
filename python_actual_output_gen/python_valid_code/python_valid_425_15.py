i=int(input())
m=[]
n=[]
for j in range(i):
  m.append(input())
for j in range(i):
  Acount=0
  Bcount=0
  for x in m[j]:
    if x=="a" or x=="c":
      Acount+=1
    if x=="b":
      Bcount+=1
  if Acount==Bcount:
    n.append("yes")
  else:
    n.append("no")
for j in range(i):
  print(n[j])