n,m,k = (int(i) for i in input().split())
ans = 'No'
for i in range(n):
  for j in range(m):
    if i*(n-j)+j*(m-i) == k:
      ans = 'Yes'
      break
print(ans)