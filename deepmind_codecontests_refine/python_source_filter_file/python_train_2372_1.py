n = int(input())
s = input()
 
r = s.count('R')
g = s.count('G')
b = s.count('B')
 
ans = r*g*b
 
for i in range(n):
  for j in range(i+1, n):
    if s[i] != s[j] and s[i] != s[int((i+j)/2)] and s[int((i+j)/2)] != s[j]:
      ans -= 1
print(ans)