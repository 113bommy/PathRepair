import sys

def minp():
	return sys.stdin.readline().strip()

def mint():
	return int(minp())

def mints():
	return map(int, minp().split())

def solve():
	n = mint()
	s = 'codeforces'
	if n <= 3**len(s):
		best = (1000,0,0)
		for i in range(len(s)+1):
			for j in range(len(s)-i+1):
				if 3**i*2**j >= n:
					best = min(best,(3*i+2*j+len(s)-i-j,i,j))
		a,b,c = best
		#print(b,c)
		for i in range(len(s)):
			if b > 0:
				b -= 1
				print(s[i]*3, end='')
			elif c > 0:
				c -= 1
				print(s[i]*2, end='')
			else:
				print(s[i], end='')
		return
	for i in range(1,100):
		if i**len(s) > n:
			m = i
			break
	#print(m)
	for i in range(len(s)+1):
		if m**i*(m-1)**(len(s)-i) >= n:
			print([m]*i+[m-1]*(len(s)-i))
			for z in range(i):
				print(s[z]*m, end='')
			for z in range(i,len(s)):
				print(s[z]*(m-1), end='')
			return

#for i in range(mint()):
solve()
