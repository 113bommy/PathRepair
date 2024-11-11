t = input()
s = list(t)
k = int(input())

ans = 0

s = s+s
for i in range(1,len(s)):
  if s[i-1] == s[i]:
    s[i] = "0"
    if i>=len(s)//2:
      ans += k-1
    else:
      ans += 1
      
if len(set(list(t))) == 1 and len(t)%2 == 1:
  ans = len(t) * (k//2) + (k%2==1)*(k//2)
print(ans)