S=input()
T=input()
ans=10**5
for i in range(len(S)-len(T)+1):
  a=0
  for j in range(len(T)):
    if S[i+j]==T[j]:
      a+=1
  ans=min(ans,len(T)-a)
print(ans)