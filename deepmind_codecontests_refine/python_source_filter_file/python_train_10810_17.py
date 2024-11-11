S = input()
for i in range(len(S)//2, 0, -1):
  if S.find(S[:i], i) == i:
    break
print(i*2)
