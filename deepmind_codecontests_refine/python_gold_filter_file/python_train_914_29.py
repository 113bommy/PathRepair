N=int(input())
H=list(map(int,input().split()))
s=1
for i in range(1,N):
  if H[i]>=max(H[0:i]):
    s+=1
print(s)