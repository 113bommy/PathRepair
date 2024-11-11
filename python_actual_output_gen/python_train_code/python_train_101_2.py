S=input()
a=1
for i in range(len(S)):
  for j in range(len(S)-i):
    if S[:i]+S[i+j+1:]=='keyence':
      a=0
print('YNEOS'[a::2])