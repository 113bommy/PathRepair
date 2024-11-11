N, C, K = map(int, input().split())
Ts = []
for i in range(N):
  T = int(input())
  Ts.append(T)
Ts.sort()
r = 0
i = 0
while i < N:
  Imin = i
  Tmin = Ts[Imin]
  while i < N:
    if i < Imin+C and Ts[i] < Tmin+K:
      i += 1
    else:
      break
  r += 1
print(r)
