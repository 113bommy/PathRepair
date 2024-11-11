N=int(input())
D, X=list(map(int,input().split()))
S=0
for i in range(N):
  A=int(input())
  A_=(D//A)+1
  S+=A_
print(S+X) 