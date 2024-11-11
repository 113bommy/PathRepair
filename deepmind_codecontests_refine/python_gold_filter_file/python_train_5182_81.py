from sys import stdin
nii=lambda:map(int,stdin.readline().split())
lnii=lambda:list(map(int,stdin.readline().split()))

n,k=nii()
p=lnii()
c=lnii()

ans=-10**18
for i in range(n):
  ini_x=i
  x=i
  point=[]

  t_ans=0
  cnt=0
  t_max=-10**18
  while True:
    x=p[x]-1
    t_point=c[x]
    point.append(t_point)
    t_ans+=t_point
    t_max=max(t_max,t_ans)
    cnt+=1
    if x==ini_x:
      break

  if t_ans<0:
    ans=max(ans,t_max)
  else:
    num=k//cnt
    num-=1
    c_ans=t_ans*num
    c_max=c_ans
    zan=k-(num*cnt)
    for j in range(zan):
      x=p[x]-1
      c_ans+=c[x]
      c_max=max(c_max,c_ans)
    ans=max(ans,c_max)

print(ans)