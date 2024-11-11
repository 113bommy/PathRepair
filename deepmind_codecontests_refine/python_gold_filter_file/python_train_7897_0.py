import sys
s=[list(map(int,e.split(',')))for e in sys.stdin]
for i in range(1,len(s)):
 for j in range(len(s[i])):
  t=j-(len(s[i])>len(s[i-1]))
  s[i][j]+=max(s[i-1][t*(j>0):t+2])
print(*s[-1])
