N=int(input())
count=1
size=1
p=list(map(int,input().split()))
q=[p[0]]
for i in range (1,N):
  if p[i]!=p[i-1]:
    q.append(p[i])
    size+=1
j=0
while True:
  if j>=size-2:
    break
  while (q[j]-q[j+1])*(q[j+1]-q[j+2])>=0:
    if j>=size-3:
      count+=1
      break
    j+=1    
  count+=1
  j+=2
print(count)