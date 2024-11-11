input()
s=input()
a=1
for t in map(s.count,set(s)):a*=-~t
print(a%(1e9+7)-1)