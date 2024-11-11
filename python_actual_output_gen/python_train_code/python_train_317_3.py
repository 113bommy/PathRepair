n=int(input())
h=list(map(int,input().split()))
c=1
for i in range(1,n):
  if h[i]>=max(h[0:i-1]):
    c+=1
print(c)