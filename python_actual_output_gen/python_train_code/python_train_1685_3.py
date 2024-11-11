N, M = list(map(int, input().split()))
D = []
L = [0] * N
for i in range(M):
  D.append(list(map(int, input().split())))
D.sort(key = lambda x: x[1])

Ans = 0
Re = 0
for i in D:
  if Re < i[0]:
    Re = i[0]
    Ans += 1
print(Ans)