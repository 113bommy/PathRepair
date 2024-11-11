S=input()
L=[0]*(len(S)+1)
#print(L)
for i in range(len(S)-1):
  if S[i]=='<':
    L[i+1]=max(L[i+1],L[i]+1)
for i in range(len(S)-1,-1,-1):
  if S[i]=='>':
    L[i]=max(L[i],L[i+1]+1)
print(sum(L))