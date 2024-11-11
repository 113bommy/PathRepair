def ctoi(c):
  return ord(c)-97

n=int(input())
s=list(input())

bits=[[0]*(n+1) for _ in range(26)]

def query(pos):
  ret=[0]*26
  for i in range(26):
    tmp=0
    p=pos
    while p>0:
      tmp+=bits[i][p]
      p-=p&(-p)
    ret[i]=tmp
  return ret

def update(pos,a,x):
  while pos<=n:
    bits[a][pos]+=x
    pos+=pos&(-pos)

for i in range(n):
  update(i+1,ctoi(s[i]),1)

q=int(input())
for _ in range(q):
  flag,a,b=map(str,input().split())
  flag=int(flag)
  a=int(a)
  if flag==1:
    if s[a-1]==b:
      continue
    else:
      update(a,ctoi(s[a-1]),-1)
      update(a,ctoi(b),1)
      s[a-1]=b
  elif flag==2:
    b=int(b)
    cnt1=query(b)
    cnt2=query(a-1)
    ans=0
    for i in range(26):
      if cnt1[i]-cnt2[i]>0:
        ans+=1
    print(ans)