S = input()
a = 0
for i in range(len(S)//2):
  if S[i] != S[-i-1]:
    a += 1
print(a)