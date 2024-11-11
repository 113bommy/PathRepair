A,B,C=(int(i) for i in input().split())
if B<=A<=C or A<=C<=B:
  print("Yes")
else:
  print("No")
