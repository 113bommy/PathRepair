n,m = map(int,input().split())
chk = [0]*n
for i in range(m):
  a,b = map(int,input().split())
  chk[a-1] += 1
  chk[b-1] += 1
ans = 'Yes'
for i in chk:
  if i % 2  == 1:
    ans = 'No'
print(ans)