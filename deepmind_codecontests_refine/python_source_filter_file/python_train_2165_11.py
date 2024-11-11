n=int(input())
a=list(map(int,input().split()))
cnt=1
for i in a:
  if i==cnt:
    cnt+=1
if cnt==1:print(-1)
else:
  print(cnt-1)