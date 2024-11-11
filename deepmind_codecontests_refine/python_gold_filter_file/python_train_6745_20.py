S = input()
T = 0
for i in range(len(S)//2):
  if S[i] != S[len(S) -1 -i]:
    T+=1
print(T)