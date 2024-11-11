n = int(input())
s = input()
ans = s.count("R")*s.count("G")*s.count("B")
for i in range(1,n//2):
  j = 0
  while j+2*i <= n-1:
    if s[j] != s[j+i] and s[j] != s[j+2*i] and s[j+i] != s[j+2*i]:
      ans -= 1
    j += 1
print(ans)