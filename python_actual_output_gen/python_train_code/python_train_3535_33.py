n=int(input())
a=list(map(int,input().split()))
b=sorted(a)
cnt=0
for i in range(n):
  if a[i]==b[i]:cnt+=1
if cnt>=n-3:print('YES')
else:print('NO')