n,k,c=map(int,input().split())
s=input()
l=[0]*n
r=[0]*n
mini=0
maxi=n-1
numl=1
numr=k
for i in range(n):
  if s[i]!='x' and i>=mini:
    l[i]=numl
    numl+=1
    mini=i+(c+1)
for i in reversed(range(n)):
  if s[i]!='x' and i<=maxi:
    r[i]=numr
    numr-=1
    maxi=i-(c+1)
for i in range(n):
  if l[i]!=0 and l[i]==r[i]:
    print(i+1)