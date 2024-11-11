n=int(input())
h=list(map(int,input().split()))
cnt=1
for i in range(1,n):
  if h[i]>=max(h[:i]):
    cnt+=1
print(cnt)