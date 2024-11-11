N=int(input())
P=list(map(int,input().split()))
M=0
c=0
for i in range(N):
  if M<P[i]:
    M=P[i]
    c+=1
print(c)
    