n=int(input())
f=True
r=0
i=1
while r<n:
  i+=1
  r=i*(i-1)//2
  if r==n:
    f=False
if f:
  print("No")
else:
  ans=[[] for j in range(i)]
  j=1
  for a in range(i):
    for b in range(a+1,i):
      ans[a].append(j)
      ans[b].append(j)
      j+=1
  print("Yes")
  print(i)
  for a in range(i):
    print(" ".join(map(str,[len(ans[a])]+ans[a])))