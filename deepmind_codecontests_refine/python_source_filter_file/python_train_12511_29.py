#sport mafia
 
DEBUG = True
 
def debug(to_print_args):
	if not DEBUG:
		return
	for arg in to_print_args:
		print(arg, end = ' ')
	print()

def solve(n, k):
	sum = 0
	for i in range(1, n):
		sum += i
		debug([sum, i])
		if sum - (n - i) == k:
			return n - i
	return 0

inp = input().split()
 
n = int(inp[0])
k = int(inp[1])

print(solve(n, k))