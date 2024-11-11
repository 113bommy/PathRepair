n,k = map(int,input().split(' '))
res = 0
for i in range(n):
  a,b = map(int,input().split(' '))
  if(b < k and a > res):
    res = a
  if(b >= k and a-b+k > res):
    res = a-b+k

print(res)
