from collections import defaultdict
N,S = open(0).read().split()
N = int(N)
ldic = defaultdict(int)
rdic = defaultdict(int)
L = S[:N]
R = S[N:][::-1]
for i in range(2**N):
  la = ''
  lb = ''
  ra = ''
  rb = ''
  for j in range(N):
    if i%2==1:
      la += L[j]
      ra += R[j]
    else:
      lb += L[j]
      rb += R[j]
    i >>= 1
  ldic[(la,lb)] += 1
  rdic[(ra,rb)] += 1
ans = sum(rdic[k]*ldic[k] for k in ldic.keys())
print(ans)