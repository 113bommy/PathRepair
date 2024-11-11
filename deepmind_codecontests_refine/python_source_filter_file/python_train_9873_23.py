n,a,b = map(int,input().split())
s = 0
for i in range(n):
  if 2 <= sum(map(int, [_ for _ in str(i)])) <= 5:
    s += i
print(s)