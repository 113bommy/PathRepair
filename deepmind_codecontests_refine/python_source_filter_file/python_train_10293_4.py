N = int(input())
A = [int(i) for i in input().split()]
cons = int(sum(A)/N)
ans = 0 
for i in range(N):
  ans += (A[i] - cons)**2 

print(ans)