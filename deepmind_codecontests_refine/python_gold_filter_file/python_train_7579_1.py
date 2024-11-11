N,K=map(int,input().split())
h=[int(input()) for i in range(N)]
h.sort()
a=10**9
for i in range(N-K+1):
  a=min(a,h[K+i-1]-h[i])
print(a)
