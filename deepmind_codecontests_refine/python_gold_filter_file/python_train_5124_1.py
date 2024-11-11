t=int(input())
for i in range(t):
  num=int(input())
  a=input()

  ali=[]
  for j in range(num):
    if a[j]=="A":
      ali.append(j)
  ali.append(num)
  sa=[0]
  for j in range(len(ali)-1):
    sa.append(ali[j+1]-ali[j]-1)
  print(max(sa))