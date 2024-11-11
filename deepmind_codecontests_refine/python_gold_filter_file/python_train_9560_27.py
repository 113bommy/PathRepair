n,m = map(int,input().split())
cnt = 0
for i in range(n,m+1):
  s = str(i)
  if s == s[::-1]:
    cnt +=1
print(cnt)