M=int(input())
N=0
S=0
for i in range(M):
  d,c=map(int,input().split())
  N +=c
  S+=d*c
print(N-1+(S-1)//9)