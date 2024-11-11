S = input()
T = input()

res = 0
for i in range(len(S)-len(T)):
  a = 0
  for j in range(len(T)):
    a += S[i+j] == T[j]
  res = max(res,a)
  
print(len(T)-res)