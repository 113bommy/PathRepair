n,m = [int(x) for x in input().split()]
cnt = [0]*(n+1)
for i in range(m):
    a,b = [int(x) for x in input().split()]
    cnt[a]+=1
    cnt[b]+=1
for i in range(n):
  if cnt[i]%2==1:
    print("No")
    exit()
print("Yes")