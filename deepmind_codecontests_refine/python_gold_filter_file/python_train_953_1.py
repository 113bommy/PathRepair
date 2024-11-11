from sys import stdin
input=stdin.readline
n,I=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
k=8*I//n
K=2**k
b=[0]
for i in range(1,n):
  if a[i-1]!=a[i]:
    b.append(i)
if len(b)<=K:
  print(0)
else:
  print(n-max(b[i+K]-b[i] for i in range(len(b)-K)))