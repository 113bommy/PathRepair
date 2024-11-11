n = int(input())
ans = 0
t = 0
for i in range(n):
  a,b = map(int,input().split())
  if a ==b:
    t+=1
  else:
    t=0
  ans = max(ans,t)
print("Yes" if ans==3 else "No")