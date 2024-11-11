s=input()
res=0
t=1
p=[0]*2019
for i in map(int,s[::-1]):
  res+=i*t
  res%=2019
  p[res]+=1
  t*=10
  t%=2019
print(p[0]+sum((i*(i-1)//2) for i in p[1:]))