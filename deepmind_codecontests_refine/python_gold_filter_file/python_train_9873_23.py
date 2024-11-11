n,a,b = map(int,input().split())
s = 0
for i in range(n+1):
  if a <= sum(map(int, [_ for _ in str(i)])) <= b:
    s += i
print(s)