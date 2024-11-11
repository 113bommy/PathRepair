I=lambda:list(map(int,input().split()))
n,m=I()
s=eval('I(),'*m)
p=I()
a=0
r=range
for i in r(1<<n):
 c=[0]*m
 for j in r(n):
  for k in r(m):c[k]+=i>>j&j+1in s[k][1:]
 a+=all(j==i%2for i,j in zip(c,p))
print(a)