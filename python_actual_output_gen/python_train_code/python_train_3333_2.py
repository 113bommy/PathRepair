n=int(input())
a=list(map(int,input().split()))
cnt=0
for i in range(n):
  if i%2 and a[i]%2:
    cnt+=1
print(cnt)