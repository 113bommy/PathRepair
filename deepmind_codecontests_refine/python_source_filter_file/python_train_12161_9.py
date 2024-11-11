n,m,c=map(int,input().split())
b=list(map(int,input().split()))
cnt =0
for i in range(n):
  a=list(map(int,input().split()))
  s=C+sum([b[j]*a[j] for j in range(m)])
  if s>0:
    cnt +=1
print(cnt)