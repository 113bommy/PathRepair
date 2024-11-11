n,k = map(int,input().split())
v = [int(i) for i in input().split()]
jewel = []
ans = 0
for i in range(min(k,n)):
  for j in range(min(k-i,n-i)):
    jewel = v[:i] + v[:-(j+1):-1]
    jewel.sort()
    temp = sum(jewel)
    leng = len(jewel)
    for m in range(k-i-j):
      if leng > m and jewel[m] < 0:
        temp += -jewel[m]
    ans = max(ans,temp)
print(ans)