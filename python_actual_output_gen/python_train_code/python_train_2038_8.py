n,k,c=map(int,input().split())
s=input()
l=[0]*k
r=[0]*k
ld=0
rd=n-1
for i in range(k):
  j=k-1-i
  while s[ld]=='x':
    ld+=1
  while s[rd]=='x':
    rd-=1
  l[i]=ld
  ld=1+c
  r[j]=rd
  rd-=1+c
for i in range(k):
  if l[i]==r[i]:
    print(l[i]+1)