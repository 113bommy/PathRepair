N=int(input())
S=input()
ans=0
for i in range(N-1):
  A=len(set(S[:i+1])&set(S[i:]))
  ans=max(A,ans)
print(ans)
    