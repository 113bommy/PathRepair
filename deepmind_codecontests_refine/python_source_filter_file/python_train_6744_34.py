n=int(input())
s=list(map(int,input().split()))
k=[0]*n
for i in s:
  k[i]+=1
for i in k:
  print(k[0])