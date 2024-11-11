N=int(input())
a=input().split()
cnt=0
for i in range(N):
  if i%2==1 and int(a[i])%2==1: cnt+=1
print(cnt)
