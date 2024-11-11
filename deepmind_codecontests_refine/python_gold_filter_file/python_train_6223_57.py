S=input()
T=input()
c=len(T)
for i in range(len(S)-len(T)+1):
  d=0
  for j in range(len(T)):
    if S[i+j]!=T[j]:
      d+=1
  if d<c:
    c=d
print(c)
    
  