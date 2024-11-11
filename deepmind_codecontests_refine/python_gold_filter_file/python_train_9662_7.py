N=int(input())
h=list(map(int,input().split()))
s=h[0]
for i in range (1,N):
  if h[i]>h[i-1]:
    s+=(h[i]-h[i-1])
print(s)