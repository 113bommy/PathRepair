m = 10**9 + 7
n = input()
a = list(map(int,input().split()))
ans = 0
s = sum(a)

for i in a:
  s -= i
  ans += s*i
  s += i

ans = ans%m

print(ans)