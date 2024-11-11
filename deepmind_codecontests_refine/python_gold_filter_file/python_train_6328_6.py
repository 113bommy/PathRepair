import math
a=int(input())
ans=0
c=[[0 for i in range(10)] for j in range(10)]
for i in range(1,a+1):
  aa=str(i)
  c[int(aa[0])][int(aa[-1])]+=1
for i in range(10):
  for j in range(10):
    ans+=c[i][j]*c[j][i]
print(ans)