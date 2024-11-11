n, m, k = map(int, input().split())
cl = list(map(int, input().split()))

pl = sorted(cl)
dic = {}
for i in range(n-m*k, n):
  dic.update({pl[i]:1})

pos = pl[n-m*k]
p = pl[n-m*k:].count(pos)


for i in range(n-m*k):
  if pl[i]!=pos:
    dic.update({pl[i]:0})

count = 0

ans = []
sm = sum(pl[n-m*k:])
for i in range(n):
  if dic[cl[i]]==1:
    if pl[i]==pos:
      if p!=0:
        count+=1
        p-=1
    else:
      count+=1
    
  if count==m:
    ans.append(i+1)
    count = 0

print(sm)
print(*ans[:k-1])