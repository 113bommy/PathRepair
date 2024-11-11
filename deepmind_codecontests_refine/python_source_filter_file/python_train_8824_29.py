n = int(input())
ans = 0
for i in range(1,n):
  k = n//i
  ans += i*(k*(k+1)//2)

print(ans)