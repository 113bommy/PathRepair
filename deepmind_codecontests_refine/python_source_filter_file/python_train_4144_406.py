A,B=map(int,input().split())
K=1
M=A
while M<B:
  K+=1
  M+=A-1
print(K)