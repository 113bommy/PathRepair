n=int(input())
a=[0]*n
for i in range(n):
  a[i]=int(input())
a=sorted(a)
S=sum(a)
if S%10!=0:
  print(S)
  exit()
else:
  for i in range(n):
    if (S-a[i])%10:
      print(S-a[i])
      exit()
print(0)