N=int(input())
S,T=map(input().split())
a=""
for i in range(N):
  a+=S[i]+T[i]
print(a)