n,m,k=map(int,input().split())
p=list(map(int,input().split()))
s=t=10000
for i in range(m-1):
   if int(p[m-1-i])!=0 and int(p[m-1-i])<=k:
      s=i*10
      break
for j in range(n-m+1):
   if int(p[m+j-1])!=0 and int(p[m+j-1])<=k:
      t=j*10
      break
print(min(s,t))