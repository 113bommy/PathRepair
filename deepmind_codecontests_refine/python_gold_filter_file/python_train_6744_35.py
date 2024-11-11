N=int(input())
A=list(map(int, input().split()))
D=[0]*N
for i in A:
  D[i-1]+=1
for i in D:
  print(i)