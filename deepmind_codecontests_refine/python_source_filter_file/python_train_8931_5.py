N,K = list(map(int,input().split()))
ans = 0
for i in range(N):
  a = i
  b = 1
  while a<K:
    a = a*2
    b = b*0.5
  ans += b*1/N
print(ans)
  
  