N=int(input())
H=list(map(int,input().split()))
s=0
for i in range(N):
  if H[i]>=max(H[0:i]):
    s+=1
print(s)