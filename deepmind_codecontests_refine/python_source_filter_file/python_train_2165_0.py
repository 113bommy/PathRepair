n=int(input())
a=list(map(int,input().split()))
m=1
for i in range(n):
  if a[i]==m:
    m+=1
if m==1:
  print(-1)
print(n-m+1)