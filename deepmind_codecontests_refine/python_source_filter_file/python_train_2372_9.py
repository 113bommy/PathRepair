n = int(input())
s = input()
r = s.count('R')
g = s.count('G')
b = s.count('B')
ans = r*g*b
for i in range(n-3):
  for j in range(i+1,n-1):
    k = 2*j-i
    if k < n:
      if  s[i] != s[j] and s[j]!= s[k] and s[i] != s[k]:
        ans -= 1
print(ans)