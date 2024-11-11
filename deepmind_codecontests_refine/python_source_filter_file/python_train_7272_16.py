N = int(input())
T = list(map(int,input().split()))
A = list(map(int,input().split()))
T_min = [0]*N
T_min[0] = T[0]
for i in range(1,N):
  if T[i-1]<T[i]:
    T_min[i] = T[i]
A_min = [0]*N
A_min[N-1] = A[N-1]
for i in range(N-2,-1,-1):
  if A[i+1]<A[i]:
    A_min[i] = A[i]
M = [0]*N
M_min = [0]*N
for i in range(N):
  M = min(T[i],A[i])
  M_min = max(T_min[i],A_min[i])
ans = 1
mod = 10**9+7
for i in range(N):
  if M[i]<M_min[i]:
    ans = 0
  else:
    ans*=M[i]+1-M_min[i]
    ans%=mod
print(ans)

