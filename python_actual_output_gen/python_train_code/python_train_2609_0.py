N,K=map(int,input().split())
h=[int(input()) for i in range(N)]
h.sort()
a=1000
for i in range(N-K+1):
  a=min(a,h[k+i-1]-h[i])
print(a)
