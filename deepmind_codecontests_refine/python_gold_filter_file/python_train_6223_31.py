S = input()
T = input()

ans = len(T)
for i in range(len(S)-len(T)+1):
  t = 0
  for j in range(len(T)):
    if S[i+j] != T[j]:
      t += 1
  ans = min(ans, t)
print (ans)