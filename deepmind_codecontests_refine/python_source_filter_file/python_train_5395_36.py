N = int(input())
M = [105,125,165,195]
T = 0
for i in range(4):
  if N >= M[i]:
    T += 1
print(T)