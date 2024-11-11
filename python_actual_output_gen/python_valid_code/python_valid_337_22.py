N=int(input())
S=input()
c=1
for i in range(N):
  if S[i]!=S[i+1]:
    c+=1
print(c)