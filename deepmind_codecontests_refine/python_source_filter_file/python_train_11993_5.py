def f(n):
	global mod
	m = len(x)
	if m >= n: return x[n-1]
	for i in range(m-n): x.append((x[-1]+x[-2])%mod)
	return x[-1]

s = input()
k = len(s)
x = [1,2,3,5,8]
ans = 1
i = 0
mod = 10**9 + 7
while i<k:
	t = s[i]
	if t == 'w' or t == 'm':
		ans = 0
		break
	elif t == 'u' or t == 'n':
		t1 = 1
		j = i+1
		while j < k:
			if s[j] == t: t1 += 1
			else: break
			j += 1
		ans = (ans*f(t1))%mod
		i = j
	else: i+=1
print(ans)