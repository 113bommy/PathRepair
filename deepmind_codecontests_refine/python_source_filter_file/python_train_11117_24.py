n,m=map(int,input().split())
ac=[0]*(n+1)
wa=0
for i in range(m):
  p,c=input().split()
  if c=='WA' and ac[int(p)]==0:
    ac[int(p)]-=1
  elif c=='AC' and ac[int(p)]<=0:
    wa+=abs(ac[int(p)])
    ac[int(p)]=1
print(ac.count(1),wa)