# from debug import debug
import sys;input = sys.stdin.readline

l = int(input())
s = input().strip()
n = len(s)

if l == 1: print(int(s)+1)
elif l>n: print(str("1"+"0"*(l-1)))
elif n%l != 0: print(str("1"+"0"*(l-1))*(n//l+1))
else:
	a = s[:l]
	b = str(int(s[:l])+1)
	g = 0
	for i in range(0, n, l):
		if a < s[i:i+l]:
			g = 1; break
	if a <= s[n-l:n]: g = 1
	if g: 
		if a == "9"*l: print(str("1"+"0"*(l-1))*(n//l + 1))
		else: print(b*(n//l))
	else: print(a*(n//l))

