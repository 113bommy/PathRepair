A,B,C=[int(s) for s in input().split()]
X=int(input())
count=0
while A<=B:
  B*=2
  count+=1
while B<=C:
  C*=2
  count+=1
if count<=X:
  print('Yes')
else:
  print('No')