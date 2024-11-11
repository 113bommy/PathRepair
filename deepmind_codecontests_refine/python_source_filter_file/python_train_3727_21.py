
n=int(input())
A=[int(i) for i in input().split()]
B=[int(i) for i in input().split()]

from heapq import heappop, heappush
push = lambda x,i: heappush(BB,(-x,i))
BB=[]

for i,b in enumerate(B):
  push(b,i)

ans=0
while BB:
  b,ind=heappop(BB)
  b,ai=-b,A[ind]
  if b<ai:
    ans=-1
    break
  d=B[(ind-1)%n]+B[(ind+1)%n]
  dd=(b-ai)//d
  if dd==0:
    if b==ai:
      continue
    ans=-1
    break
  ans+=dd
  B[ind]-=d*dd
  push(B[ind],ind)
  
print(ans)
