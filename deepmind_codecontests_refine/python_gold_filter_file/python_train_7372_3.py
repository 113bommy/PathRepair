d,g=map(int,input().split())
pc=[list(map(int,input().split())) for _ in range(d)]
ans=0
for i in range(1<<d):
  p=0
  cnt=0
  for j in range(d):
    if (i>>j)&1:
      p+=100*(j+1)*pc[j][0]+pc[j][1]
      cnt+=pc[j][0]
  if g>p:
    for k in range(d)[::-1]:
      if (i>>k)&1==0:
        if g-p<=100*(k+1)*(pc[k][0]-1):
          cnt+=-(-(g-p)//(100*(k+1)))
          break
        else:
          cnt=10**5
          break
  if ans==0 or ans>cnt:
    ans=cnt
print(ans)