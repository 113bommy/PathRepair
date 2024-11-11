c1=int(input())
for n1 in range(0,c1):
  c2=int(input())
  l=input().split()
  s=0
  for n2 in range(0,c2):
    if int(l[n2])==2048:
      s=0
      break
    elif int(l[n2])<2048:
      s=s+int(l[n2])
  if s>=2048 or s==0:
    print("YES")
  else:
    print("NO")