# problem statement: https://codeforces.com/problemset/problem/625/A

n = int(input())
a = int(input())
b = int(input())
c = int(input())

if (b-c < a) and (n > b):
	count_gb = ((n-b)//(b-c)) + 1
	count_ga = (n - (count_gb * (b-c)))//a
	print(count_gb + count_ga)
else:
	print(n//a)
