n = int(input())
a = list(map(int,input().split()))
m =max(a)
arr = [0]*(m+1)

for i in a:
  for j in range(i,m+1,i):
    arr[j]+=1

cnt = 0
for i in a:
  if arr[i] ==1:
    cnt += 1

print(cnt)