s=input()
k=int(input())
n=len(s)
ans=0
tmp=0
x=s[0]
ss=[]
for i in range(n):
  if x==s[i]:
    tmp+=1
  else:
    ss.append(tmp)
    tmp=1
    x=s[i]
if tmp>0:
  ss.append(tmp)
if len(ss)==1:
  print(n*k//2)
else:
  if not s[0]==s[-1]:
    ans+=(-ss[0]//2-ss[-1]//2+(ss[0]+ss[-1])//2)*(k-1)
  for i in ss:
    ans+=i//2*k
  print(ans)