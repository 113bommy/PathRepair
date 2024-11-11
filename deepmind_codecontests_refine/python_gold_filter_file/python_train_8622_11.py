n=int(input())
q=[list(map(int,input().split())) for _ in range(n)]
MAX=100010
p=[1]*MAX
p[0]=0;p[1]=0
for i in range(2,MAX):
  if not p[i]:continue
  for j in range(i*2,MAX,i):p[j]=0
a=[0]*MAX
for i in range(MAX):
  if i%2==0:continue
  if p[i] and p[int((i+1)/2)]:a[i]=1
s=[0]*(MAX+1)
for i in range(MAX):
  s[i+1]=s[i]+a[i]
for i in range(n):
  print(s[q[i][1]+1]-s[q[i][0]])