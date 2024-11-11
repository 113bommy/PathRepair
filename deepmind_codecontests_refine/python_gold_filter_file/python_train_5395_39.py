N = int(input())
M = [105,135,165,189,195]
T = 0
for i in range(5):
  if N >= M[i]:
    T += 1
print(T)