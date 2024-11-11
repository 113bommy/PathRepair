s = input()
# s = "aiajadabaa"
n = len(s)

L = [0] * n  # L[i] = số lượng xâu đối xứng trong đoạn s[0..i]
R = [0] * n  # R[i] = số lượng xâu đối xứng trong đoạn s[i+1..n-1]

for i in range(n):
	x = y = i
	while x >= 0 and y < n and s[x] == s[y]:
		R[x] += 1
		L[y] += 1
		x -= 1
		y += 1
for i in range(1, n):
	if s[i - 1] == s[i]:
		x, y = i-1, i
		while x >= 0 and y < n and s[x] == s[y]:
			R[x] += 1
			L[y] += 1
			x -= 1
			y += 1

for i in range(n - 1):
	L[i + 1] += L[i]
	
p = 0
for i in range(1, n):
	p += L[i-1] * R[i]

print(p)
