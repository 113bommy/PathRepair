N,C,K = map(int,input().split())
T = sorted([int(input()) for x in range(N)])

ans = 0
it = 0
while it < N:
  start = T[it]
  occupancy = 0
  while it < N and occupancy < C and T[it] < start + K:
    occupancy += 1
    it += 1
  ans += 1
print(ans)