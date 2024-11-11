N=int(input())
H=list(map(int,input().split()))

cnt=0

for i in range(0,N):
  if max(H[0:i+1]) <= H[i]:
    cnt+=1
print(cnt)
