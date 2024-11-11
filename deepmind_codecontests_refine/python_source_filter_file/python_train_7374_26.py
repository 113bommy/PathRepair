n = int(input())
ans = 0
for i in range(n):
  a,b = map(int,input().split())
  ans += b-a-1
  
print(ans)  