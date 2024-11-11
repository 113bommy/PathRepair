
N=int(input())
S=input()

white=S.count(".")
countb=0
ans=10**9

for i in range (len(S)):
  if S[i]==".":
    white -=1
  else:
    countb +=1 
  ans=min(ans, countb+white)

print(ans)