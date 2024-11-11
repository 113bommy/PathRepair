n,k = map(int,input().split())
s = input()
s = [s.count(s[i]) for i in range(n) if s[i] not in s[:i]]
c = 0

for i in s:
	if i > n//2:
		c+=1

if c==0:
	print("YES")
else:
	print("NO")