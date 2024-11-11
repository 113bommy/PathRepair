# http://codeforces.com/problemset/problem/918/A

n = int(input())
def solve(n):
	if n == 1:
		print("O")
		return  
	elif n == 2:
		print("OO")
		return 
	else:
		l  = [None]*(n+1)
		l[0]= 1
		l[1]= 1
		for i in range(2,n+1):
			l[i] = l[i-1]+l[i-2]
		ans = []
		for i in range(n):
			if((i+1) in l):
				ans.append('O')
			else:
				ans.append('o')
		print("".join(ans))
		return
solve(n)
