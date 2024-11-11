N=int(input())
A=list(map(int, input().split()))
c=[0]*N
for i in A:
  c[i-1]+=1
for a in c:
  print(a)