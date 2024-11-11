n,m=map(int,input().split())
cnt=[]
for i in range(n):
  cnt.append(0)
for i in range(m):
  a,b=map(int,input().split())
  cnt[a-1]+=1
  cnt[b-1]+=1
for i in range(n):
  if cnt[i]%2==1:
    print('NO')
    exit()
print('Yes')