import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int,minp().split())

def solve():
	n = mint()

	s = list(minp())
	t = list(minp())
	if sorted(t) != sorted(s):
		print("NO")
		return
	if len(s) > 26:
		print("YES")
		return

	for i in range(26):
		if s.count(chr(ord('a')+i)) > 1:
			print("YES")
			return
	r = 0
	for i in range(len(s)):
		if s[i] != t[i]:
			jj = i
			for j in range(i+1,len(s)):
				if s[j] == t[i]:
					jj = j
					break
			for j in range(jj-1,i-1,-1):
				s[j],s[j+1] == s[j+1], s[j]
				r += 1
	#print(r)
	print(["NO","YES"][r%2 == 0])

for i in range(mint()):
	solve()
