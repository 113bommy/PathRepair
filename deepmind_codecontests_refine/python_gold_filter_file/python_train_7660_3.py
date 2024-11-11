n=int(input())
L=list(map(int,input().split(' ')))
zeros=[]
zeros.append(10000000)
for i in range(n):
  if L[i]==0:
    zeros.append(i)
k=len(zeros)
j=1

dist=[]

for i in range(n):
  
  if j<k-1 and i-zeros[j]==0:
    j=j+1
  
  dist.append(min(abs(i-zeros[j-1]),abs(i-zeros[j])))
for i in range(n-1):
  print(dist[i],end=' ')
print(dist[len(dist)-1])

  