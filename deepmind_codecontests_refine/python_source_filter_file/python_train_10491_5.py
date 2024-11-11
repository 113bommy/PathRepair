n, k = map(int, input().split())
A = list(map(int, input().split()))

MOD = 10 ** 9 + 7

AA = sorted(A, key=lambda x: -abs(x))

nega1 = []
posi1 = []
for a in AA[:k]:
  if a < 0:
    nega1.append(a)
  else:
    posi1.append(a)

nega2 = []
posi2 = []
for a in AA[k:]:
  if a < 0:
    nega2.append(a)
  else:
    posi2.append(a)

if all(a < 0 for a in A) and k % 2 == 1:
  AA = sorted(A, key=lambda x: abs(x))
  nega1 = []
  posi1 = []
  for a in AA[:k]:
    nega1.append(a)

elif n == k:
  pass

elif len(nega1) % 2 != 0:
  if posi1 and nega2 and posi2:
    if abs(nega1[-1] * nega2[0]) > abs(posi1[-1] * posi2[0]):
      del nega1[-1]
      nega1.append(posi2[0])
    else:
      del posi1[-1]
      posi1.append(nega2[0])
  elif not posi1 or not nega2:
    del nega1[-1]
    nega1.append(posi2[0])
  elif not posi2:
    del posi1[-1]
    posi1.append(nega2[0])
  
a = 1
for m in posi1:
  a = (a * m) % MOD
for p in nega1:
  a = (a * p) % MOD
 
print(a)