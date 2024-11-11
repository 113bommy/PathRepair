n=int(input())
j=1
a=0
while j<=n:
  d=0
  for i in range(1,j):
    if j%i==0:
      d+=1
  if d==8:
    a+=1
  j+=2
print(a)
