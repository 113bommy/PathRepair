n=int(input())
a=list(map(int,input().split()))
c=[0]*10
for i in range(n):
  c[a[i]]+=1
if c[0]==0:
  print(-1)
  exit()
c[0]-=1 # for last
m=0
for i in range(1,10):
  m+=c[i]*i
  m%=3
if m%3==1:
  if c[1]>0:
    c[1]-=1
    m-=1
  elif c[4]>0:
    c[4]-=1
    m-=1
  elif c[7]>0:
    c[7]-=1
    m-=1
  else:
    res=2
    if c[2]>=2:
      res-=2
      c[2]-=2
      m-=1
    elif c[2]==1:
      res-=1
      c[2]-=1
      m-=2
    if res==2 and c[5]>=2:
      res-=2
      c[5]-=2
      m-=1
    elif res>=1 and c[5]>=1:
      res-=1
      c[5]-=1
      m-=2
    if res==2 and c[8]>=2:
      res-=2
      c[8]-=2
      m-=1
    elif res>=1 and c[8]>=1:
      res-=1
      c[8]-=1
      m-=2
elif m%3==2:
  if c[2]>0:
    c[2]-=1
    m-=2
  elif c[5]>0:
    c[5]-=1
    m-=2
  elif c[8]>0:
    c[8]-=1
    m-=2
  else:
    res=2
    if c[1]>=2:
      res-=2
      c[1]-=2
      m-=2
    elif c[1]==1:
      res-=1
      c[1]-=1
      m-=1
    if res==2 and c[4]>=2:
      res-=2
      c[4]-=2
      m-=2
    elif res>=1 and c[4]>=1:
      res-=1
      c[4]-=1
      m-=1
    if res==2 and c[7]>=2:
      res-=2
      c[7]-=2
      m-=2
    elif res>=1 and c[7]>=1:
      res-=1
      c[7]-=1
      m-=1
if m%3!=0:
  print(-1)
  exit()
ans=["0"]
for i in range(10):
  ans.extend([str(i)]*c[i])
while len(ans)>1 and ans[-1]=="0":
  ans.pop()
ans=ans[::-1]
print("".join(ans))