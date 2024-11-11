#author : SanskarxRawat
n=int(input())
lst=list(map(int,input().strip().split()))[:n]
for i in range(n):
  s=[1]*n
  while s[i]:s[i]=0;i=lst[i]-1
  print(i+1,end=" ")