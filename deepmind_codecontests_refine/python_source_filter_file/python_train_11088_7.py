n = int(input())
s = input().strip()
ret = 1
nb2 = 0
for i in range(1,n):
  if s[i-1] != s[i]:
    ret += 1
  else:
    nb2 += 1
if nb2 >= 2:
  ret += 2
else:
  ret += 1
print(ret)
