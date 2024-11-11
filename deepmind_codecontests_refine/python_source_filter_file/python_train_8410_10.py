N,K,*A = map(int, open(0).read().split())
pls = []
S = sum(A)
for i in range(1,int(S**0.5)+1):
  if S%i==0:
    pls.append(i)
    pls.append(S//i)
pls.sort()
ans = 0
for p in pls:
  B = [a%p for a in A]
  B.sort()
  i = 0
  j = N-1
  cnt = K
  while i<N:
    if B[i]!=0:
      break
    i += 1
  else:
    ans = p
    continue
  while True:
    a = B[i]
    b = B[j]
    if a<p-b:
      if cnt<a:
        break
      b += a
      cnt -= a
      i += 1
    elif a>p-b:
      if cnt<p-b:
        break
      a -= p-b
      cnt -= p-b
      j -= 1
    else:
      if cnt<a:
        break
      cnt -= a
      i += 1
      j -= 1
    if i>=j:
      ans = p
      break
print(ans)