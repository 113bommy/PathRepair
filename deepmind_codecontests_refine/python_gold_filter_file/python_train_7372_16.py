d , g = map(int , input().split())
p = [0] * d
c = [0] * d
for i in range(d):
    p[i] , c[i] = map(int , input().split())

ans = float("inf")

for bit in range(1<<d):
  sum=0
  count=0
  nokori=set(range(1,d+1))
  for i in range(d):
    if bit&(1<<i):
      sum += p[i]*100*(i+1)+c[i]
      count+= p[i]
      nokori.discard(i + 1)
  if sum<g:
    a=g-sum
    num=max(nokori)
    n=min(p[num-1],-(-a//(num*100)))
    count+=n
    sum+=n*num*100
  if sum>=g:
    ans=min(ans,count)
    
print(ans)