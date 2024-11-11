N=int(input())
S=input()
ans=0

for i in range(1,N):
  x=S[0:i]
  y=S[i:N]
  ans=max(len(set(x)&set(y)),ans)
  
print(ans)