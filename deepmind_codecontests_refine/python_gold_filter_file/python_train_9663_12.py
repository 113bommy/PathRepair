S = input()
a = [1,0,0,0]

for s in S:
  if s=="A":
    a[1]+=a[0]
  elif s=="B":
    a[2]+=a[1]
  elif s=="C":
    a[3]+=a[2]
  else:
    a=[3*a[0]]+[3*a[n+1]+a[n] for n in range(3)]
  a=[a[n]%1000000007 for n in range(4)]

print(a[3])