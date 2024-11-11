n=int(input())
s=input()
c=1
for i in range(1,N):
  if not(S[i]==S[i-1]):c+=1
print(c)