S=list(str(input().split()))
G='CODEFESTIVAL2016'
t=0
for i in range(16):
  if S[i]!=G[i]:
    t+=1
print(t)