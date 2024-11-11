import math
N,M=map(int,input().split())

if(N%2==1):
  for i in range(M):
    print(i+1,N-i)
else:
  for i in range(min(M,N//2)):
    print(i+1,N//2-i)
  for i in range(min(M-N//2,0)):
    print(N//2+1+i,N-1-i)