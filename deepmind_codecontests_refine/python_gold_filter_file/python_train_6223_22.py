S = input()
T = input()

ans = len(T)
for i in range(len(S)-len(T)+1):
  a = 0
  for j in range(len(T)):
    if S[i+j]!=T[j]:
      a += 1
  ans = min(ans, a)
print(ans)
