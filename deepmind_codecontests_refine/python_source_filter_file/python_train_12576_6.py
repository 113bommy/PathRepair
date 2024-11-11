n = int(input())
a = 0
b = 0
x = 0
ans = 0
for i in range(n):
  s = input()
  ans += s.count("AB")
  a += s[-1] == "A"
  b += s[0] == "B"
  x += (s[-1] == "A") and (s[0] == "B")
if a == x == b:
  ans += x-1
else:
  ans += min(n-1,a,b)
print(ans)
