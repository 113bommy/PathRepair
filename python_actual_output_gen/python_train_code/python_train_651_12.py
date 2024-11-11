n,x,y = map(int, input().split())

ans = [0]*n
for i in range(n-1):
  for j in range(i+1, n):
    d = min(j-i, abs(x-i)+abs(y-j)+1)
    ans[d] += 1
    
ans = ans[1:]

for a in ans:
  print(a)
