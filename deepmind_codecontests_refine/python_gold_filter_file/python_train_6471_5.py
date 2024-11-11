# https://codeforces.com/problemset/problem/1177/A

n = int(input())

if n < 10:
	print(n)
else:
	l = [str(x) for x in range(1,n+1)]
	string = ''.join(l)

	# print(string)
	print(string[n-1])