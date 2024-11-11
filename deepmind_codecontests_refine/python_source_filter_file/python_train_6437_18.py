S = input()

mi = len(S) // 2 + len(S) % 2 

if len(S) % 2 == 0:
  l = mi - 1
  r = mi
  if S[l] != S[r]:
    print(r)
    exit()
else:
  l = mi - 1
  r = mi - 1

re = S[l]
for i in range(l):
  if S[l - 1 - i] != re or S[r + 1 - i] != re:
    ans = r + i + 1
    break
else:
  ans = len(S)


print(ans)