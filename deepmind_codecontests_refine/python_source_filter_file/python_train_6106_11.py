import sys
input=sys.stdin.readline
n=int(input())
a=list(map(int,input().split()))
b=list(input().rstrip())
for i in range(n):
  b[i]=int(b[i])
l,r=-10**18,10**18
for i in range(4,n):
  if b[i]==b[i-1]:
    if not b[i-1]==b[i-2]==b[i-3]==b[i-4]:
      continue
    if b[i]==0:
      if max(a[i-4:i+1])<l:
        l=max(a[i-4:i+1])-1
    else:
      if min(a[i-4:i+1])>r:
        r=min(a[i-4:i+1])+1
  else:
    if b[i]==1:
      if max(a[i-4:i+1])>=l:
        l=max(a[i-4:i+1])+1
    else:
      if min(a[i-4:i+1])<=r:
        r=min(a[i-4:i+1])-1
print(l,r)