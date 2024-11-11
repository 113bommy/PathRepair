n = int(input())
s = [2]
q = 1

for i in range(n+1):
	if i<3:
		continue
	t = []
	for j in range(len(s)):
		t.append((i)%s[j])
	if 0 in t:
		q = 3
	else:
		s.append(i)

x = 1

for i in range(len(s)):
	m = 0
	for j in range(10):
		m += n//(s[i]**(j+1))
	x *= m+1
print(x%(10**9+7))
