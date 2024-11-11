'''input
1 1
1 100000
'''
n, x = map(int, input().split())
minutes = 0
current = 1
for _ in range(n):
	l, r = map(int, input().split())

	skip = ((l - current)//x)*x
	current += skip 
	minutes += r - current +1
	current = r+1

print(minutes)

		


