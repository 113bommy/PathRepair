N, M = list(map(int, input().split()))
AC = [0] * N
WA = [0] * N
for i in range(M):
  p, S = input().split()
  p = int(p)
  if(S == "AC"):
    AC[p-1] = 1
  elif(AC[p-1] == 0):
    WA[p-1] += 1
for i in range(M):
  if(AC[i] == 0):
    WA[i] = 0
print(sum(AC), sum(WA))