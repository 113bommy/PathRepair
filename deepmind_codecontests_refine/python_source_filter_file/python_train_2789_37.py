N=int(input())
d+=list(map(int,input().split()))
s=0
for j in range(N-1):
  for i in range(j+1,N):
    s+=d[j]*d[i]
print(s)