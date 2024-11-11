s = input()
l = len(s)
ret = 0
for i in range(l): 
  ret += (s[i] != s[-i-1])
print(ret//2)
