S=input()
T=input()
ans=len(T)
for i in range(len(S)-len(T)+1):
  _ans=0
  for j in range(len(T)):
    if S[i+j]!=T[j]:
      _ans+=1
  ans=min(ans,_ans)
print(ans)