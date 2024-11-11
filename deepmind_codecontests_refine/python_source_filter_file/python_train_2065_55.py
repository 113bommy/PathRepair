N=int(input())
A=list(map(int,input().split()))
a=0
while all(X%2==0 for X in A):
  A=[a//2 for X in A]
  a+=1
print(a)