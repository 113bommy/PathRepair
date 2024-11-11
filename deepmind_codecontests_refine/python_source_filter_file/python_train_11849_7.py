Mod = 10**9+7
n = int(input())
s = input()
k = 1
for i in range(97,97+26):
  k = (k * s.count(chr(i))+1)%Mod
print((k-1)%Mod)