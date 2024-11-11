n = int(input())
a = list(map(int, input().split()))
m = sum(a)/n
ans = []
for x,y in enumerate(a):
  ans.append([x, abs(m-y)])
ans.sort(key=lambda x:x[1])
print(ans[0][0])