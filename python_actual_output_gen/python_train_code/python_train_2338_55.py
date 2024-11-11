s = input()
l = len(s)
ret = 0
for i in range(l): ret += (s[l] != s[-l-1])
print(ret//2)