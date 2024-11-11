N, C = map(int, input().split())
table = [[0]*10000 for i in range(C)]

for i in range(N):
  s, t, c = map(int, input().split())
  table[c-1][s-1:t] = [1]*(t-s+1)

print(max(map(sum, zip(*table))))