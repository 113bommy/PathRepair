N=int(input())
S={}

for i in range(N):
  p,q=input().split()
  S[i+1]=(p,int(q))
S=sorted(S,key=lambda x:(S[x][0],-S[x][1]))
print(S)

print(*S,sep="\n")