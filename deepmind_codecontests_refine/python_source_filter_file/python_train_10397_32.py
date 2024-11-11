from bisect import bisect_left as bl
N, K = map(list, input().split())
D = list(map(int, input().split()))
D = [i for i in range(10) if not i in D]
res = []
big = 0
if int("".join([str(D[-1])] * len(N))) < int("".join(N)):
  if int(K[0]) < 9:
    if D[0] == 0:
      res = [D[1]] + [0] * len(N)
    else:
      res = [D[1]] * (len(N) + 1)
  else:
    res = [D[0]] * (len(N) + 1)
else:
  for i in range(len(N)):
    if big == 0:
      res.append(D[bl(D, int(N[i]))])
    else: res.append(D[0])
    if res[i] > int(N[i]): big = 1
print("".join(list(map(str, res))))