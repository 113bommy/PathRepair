N=int(input())
S=input()
ans=0

for i in range(N):
  x=S[0:i]
  y=S[i-1:N]
  ans=max(len(set(x)&set(y)),ans)
  
print(ans)