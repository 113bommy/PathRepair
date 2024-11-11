a = int(input())
l5 = []
while a > 0:
  c = int(input())
  l = [i for i in input().lower()[:c]]
  l1 = [j for j in input().lower()[:c]]
  l3, l4 = [], []
  for i in range(c):
    if l[i] != l1[i]:
      l3.append(l[i])
      l4.append(l1[i])
    else :
      pass
  if len(l3)==2 and l3[0]==l4[1] and l3[1]==l4[0]:
    l5.append('Yes')
  else :
    l5.append('No')
  a -= 1
for i in l5:
  print(i)