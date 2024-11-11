n = int(input())
bn = list(map(int,input().split()))

ans = []

while bn:
  lst = []
  for i in range(len(bn))[::-1]:
    if i+1 == bn[i]:
      lst.append(i)
  if not lst:
    print(-1)
    exit(0)
  ans.append(bn.pop(lst[-1]))
[print(i) for i in ans[::-1]]
