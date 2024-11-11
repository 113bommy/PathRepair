N, M = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(M)]

U = [0] * (N + 2)
for A, B in AB:
  U[A + 1] += 1
  U[B + 1] -= 1
#print("U:", U)

for u in U:
  if u % 2:
    print("No")
    exit()
print("Yes")