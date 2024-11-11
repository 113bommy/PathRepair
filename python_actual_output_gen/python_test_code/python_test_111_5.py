N = int(input())
H = list(map(int,input().split()))
ans = 0
x = 0
for i in range(N-1):
  if x[i] > x[i+1]:
    x += 1
    ans = max(ans,x)
  else:
    x = 0
print(ans)