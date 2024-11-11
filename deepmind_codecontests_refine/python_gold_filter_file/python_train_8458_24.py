t=int(input())
result=[]
for _ in range(t):
  n=int(input())

  ans=[]
  permu = [int(x) for x in input().split()]
  for i in permu:
    if i not in ans:
      ans.append(i)
    else:
      continue
  result.append(ans)

for res in result:
  print(*res)