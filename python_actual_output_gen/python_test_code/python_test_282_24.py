def hamb(n,x):
  if x<=n:return 0
  elif x==1 and n==0:return 1
  elif x<=s[n-1]+1:return hamb(n-1,x-1)
  elif x==s[n-1]+2:return p[n-1]+1
  else:return hamb(n-1,x-2-s[n-1])+p[n-1]+1
n,x=map(int,input().split())
s=[0]*(n+1)
p=[0]*(n+1)
s[0]=1
p[0]=1
for i in range(n):
  s[i+1]=3+2*s[i]
  p[i+1]=1+2*p[i]
print(hamb(n,x)) 