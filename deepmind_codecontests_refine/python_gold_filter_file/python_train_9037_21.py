n=int(input())
a=[int(input()) for i in range(n)]

if a[0]!=0:
  print(-1)
  exit()

cnt=0
for i in range(1,n):
  if a[i]==0:
    continue
  elif a[i]==a[i-1]+1:
    cnt+=1
  elif a[i]==a[i-1]:
    cnt+=a[i]
  elif a[i]<a[i-1]:
    cnt+=a[i]
  else:
    print(-1)
    exit()

print(cnt)