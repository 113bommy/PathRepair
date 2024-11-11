n=int(input())
A=list(map(int,input().split()))
cnt=0
for i in range(n):
  if A[i]%2!=i%2:
    cnt+=1
print(cnt)		