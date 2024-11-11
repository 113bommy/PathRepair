n, p = map(int, input().split())
p += ord('a') - 1
s = [*input()]

from string import ascii_lowercase
ap = [*ascii_lowercase]

def check(m):
	i = 1
	z = len(m)
	if z > 1 and m[0] == m[1]:
		return False
	while i < z - 1:
		t1 = m[i] + m[i + 1]
		t2 = m[i - 1] + m[i] + m[i + 1]
		if t1 == t1[::-1] or t2 == t2[::-1]:
			return False
		i += 1

	return True

i = n - 1
ans = 'NO'
t = s[i]

while i >= 0:
	if ord(t) == p:
		i -= 1
		t = s[i]
		continue

	t = chr(ord(t) + 1)
	m = [j for j in s]
	m[i] = t
	if check(m[:i + 1]):
		j = i + 1
		f = True
		while j < n:
			l = 97
			while l < 123:
				if (j > 2 and ord(m[j - 2]) == l) or ord(m[j - 1]) == l:
					l += 1
				else:
					break
			if l == 123:
				f = False
				break
			m[j] = chr(l)
			j += 1
		m[i] = t
		if f:
			print(''.join(m))
			exit()

print(ans)