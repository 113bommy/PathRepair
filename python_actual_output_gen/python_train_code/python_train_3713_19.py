n = int(input())
s = input()
x = 0
i = 0
for i in range(len(s)):
  i = i + (s[i]=='I') - (s[i]=='D')
  x = max(x,i)
print(x)