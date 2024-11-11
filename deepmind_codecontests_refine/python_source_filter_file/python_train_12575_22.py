N=int(input())
S=input()
ans=0
for i in range(N-1):
  #jstart=i+ans+1
  for j in range(jstart,N):
    if S[i:j] in S[j:]:
      ans=max(ans,j-i)
    else:
      break
print(ans)