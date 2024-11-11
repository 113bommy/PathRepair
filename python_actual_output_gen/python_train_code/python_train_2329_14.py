n = int(input())
ans = list()
for i in range(1,n):
  if n%i == 0:
    x = int(n/i)
  it = [x,i]
  it.sort()
  ans.append((abs(it[0] - it[1]) , (it[0] , it[1]) ))
  
ans.sort()
print(ans[0][1][0] , ans[0][1][0])