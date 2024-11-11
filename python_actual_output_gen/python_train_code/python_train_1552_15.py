ans=0
shogen=[]
n=int(input())
for _ in range(n):
  t=[]
  a=int(input())
  for __ in range(a):
    h=list(map(int,input().split()))
    t.append(s)
  shogen.append(t)
for i in range(2**n):
  flag=True
  for j in range(n):
    if not flag:
      break
    if ((i>>j) & 1):
      for h in shogen[j]:
        if ((i>>h[0]-1)&1) !=h[1]:
          flag=False
  if flag:
    mnt = bin(i).count("1")
    ans=max(ans,mnt)
print(ans)
