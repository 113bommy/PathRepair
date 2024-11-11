N, K = map(int, input().split())
As = list(map(int, input().split()))
P = 10**9 + 7

As.sort()
dic = {-1:0, 1:0}
for a in As:
  if a < 0:
    dic[-1] += 1
  else:
    dic[1] += 1

rlt = 1
j = 0
if N == K:
  for a in As:
    rlt *= a
    rlt %= P
  while rlt < 0:
    rlt += P
elif As[N-1] < 0 and K%2 == 1:
  for i in range(1,K+1):
    rlt *= As[-i]
    rlt %= P
  while rlt < 0:
    rlt += P
else:
  s = 0
  i = 0
  j = 1
  while s < K:
    if i+1 >= dic[-1] or s+1 == K:
      rlt *= As[-j]
      rlt %= P
      j += 1
      s += 1
    elif j+1 > dic[1]:
      rlt *= As[i]*As[i+1]
      rlt %= P
      j += 2
      s += 2
    else:
      if As[i]*As[i+1] > As[-j]*As[-(j+1)]:
        rlt *= As[i]*As[i+1]
        rlt %= P
        j += 2
        s += 2
      else:
        rlt *= As[-j]
        rlt %= P
        j += 1
        s += 1
        
print(rlt)