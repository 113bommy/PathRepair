import heapq
n=int(input())
A=[int(i) for i in input().split()]
AL=A[:n]
AR=[0]*n
for i in range(2*n,3*n):
  AR[i-2*n]-=A[i]
ALS,ARS=[0]*(n+1),[0]*(n+1)
ALS[0],ARS[0]=sum(AL),-sum(AR)
heapq.heapify(AL)
heapq.heapify(AR)
for i in range(n):
  l,r=A[n+i],-A[2*n-i-1]
  heapq.heappush(AL,l)
  ALS[i+1]=ALS[i]+l-heapq.heappop(AL)
  heapq.heappush(AR,r)
  ARS[i+1]=ARS[i]+r-heapq.heappop(AR)
ans=-float("inf")
for i in range(n+1):
  ans=max(ans,ALS[i]-ARS[n-i])
print(ans)