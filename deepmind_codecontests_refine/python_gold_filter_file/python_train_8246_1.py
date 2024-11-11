# from debug import debug

n = int(input())
s = input()

def sol(s):
	n = len(s)
	if n == 1:
		return 0
	else:
		ans = 0
		m = 'a'
		ind = -1
		for i in range(n):
			f, b = min(n-1, i+1), max(0, i-1)
			if ord(s[i])-ord(s[f]) == 1 or ord(s[i])-ord(s[b]) == 1:
				if s[i]>m:
					m = s[i]
					ind = i
		if ind == -1:
			return 0
		else:
			if ind == 0:
				v = 1+sol(s[ind+1:])
			elif ind == n-1:
				v = 1+sol(s[:n-1])
			else:
				v= 1+sol(s[:ind]+s[ind+1:])
		return v
print(sol(s))