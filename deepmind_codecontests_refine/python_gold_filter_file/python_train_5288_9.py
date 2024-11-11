n, k = map(int, input().split())
r, s, p = map(int, input().split())
t = list(input())
hand = {"r" : p, "s" : r, "p" : s}
ans = 0
for i in range(n):
  temp= i-k
  if temp >=0 and t[i]==t[temp]:
    t[i]=" "
  else:
    ans+=hand[t[i]]
print(ans)