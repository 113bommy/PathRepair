N=int(input())
S,T=input().split("")
P=""
for i in range(N):
  P=P+S[i]+T[i]
print(P)