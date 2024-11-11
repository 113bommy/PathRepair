n,c=map(int,input().split())
a=[]
tf=0
for _ in range(n):
  s,t,ch=map(int,input().split())
  a+=[(ch,s,t)]
a=sorted(a)
flag=a[0][0]
ans=[0]*(10**5+1)
tf=0
for ch,s,t, in a:
  if ch==flag and tf==s:ans[s]+=1
  else:ans[s-1]+=1
  ans[t]-=1
  tf=t
  flag=ch
for i in range(10**5):
  ans[i+1]+=ans[i]
print(max(ans))