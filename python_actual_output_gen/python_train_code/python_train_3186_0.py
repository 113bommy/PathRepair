def f(k):
  if mem[k]!=-1:
    return mem[k]
  t=a[k]
  ans="B"
  for i in range(k,-1,t):
    if a[i]>t:
      if f(i)=="B":
        ans="A"
  for i in range(k,n,t):
    if a[i]>t:
      if f(i)=="B":
        ans="A"
  mem[k]=ans
  return ans
n=int(input())
a=list(map(int,input().split()))
mem=[-1]*n
for i in range(n):
  f(i)
print("".join(mem))