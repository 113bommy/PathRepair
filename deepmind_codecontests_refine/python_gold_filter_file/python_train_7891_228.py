S=input()
ans=10**9
for i in range(len(S)):
  ans=min(ans,abs(int(S[i:i+3])-753))
print(ans)