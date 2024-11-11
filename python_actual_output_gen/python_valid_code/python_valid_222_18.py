n = int(input())
ab = []
for _ in range(n):
  a,b = map(int,input().split())
  ab.append([a,b])
ab.sort(key = lambda x:x[0]+x[1] ,reverse = True)
ans = sum([x[0]+x[1] for x in ab[0:(n+1)//2]])-sum([x[1] for x in ab])
print(ans)


