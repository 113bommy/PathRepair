N=int(input())
S=input()
ans = 0
for i in range(N-1):
  if S[i] != S[i+1]:
    ans += 1
print(ans)