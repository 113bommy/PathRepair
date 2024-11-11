N=int(input())
a=list(map(int,input().split()))

l=[]
r=[]
s=[]

for i,x in enumerate(a):
  left=i
  while len(s)>0 and x<s[-1][0]:
    left=s[-1][-1]
    s.pop()
  l.append(left)
  s.append([x,left])
  #print(l)
  #print(s)
s=[]
for i in range(N-1,-1,-1):
  right=i
  x=a[i]
  while len(s)>0 and x<s[-1][0]:
    right=s[-1][-1]
    s.pop()
  r.append(right)
  s.append([x,right])
r=r[::-1]
ans=0
for i,(x,le,ri) in enumerate(zip(a,l,r)):
  ans+=x*(i-le+1)*(ri-i+1)
print(ans)