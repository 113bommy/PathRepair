N=int(input())
S=input()
ans=0
for i in range(N):
  A=len(set(S[:i+1])&set(S[i+1:]))
  ans=max(A,ans)
print(ans)