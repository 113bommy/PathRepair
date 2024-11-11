M=int(input())
N=0
S=0
for i in range(M):
  d,c=map(int,input().split())
  N +=c
  S+=d*c
print(N+S//9-1)