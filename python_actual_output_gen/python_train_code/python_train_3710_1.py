n = int(input())
v = list(map(int,input().split()))
c = list(map(int,input().split()))
ans = 0
for i,j in zip(v,c):
  ans += max(0, v-c)
print(ans)
