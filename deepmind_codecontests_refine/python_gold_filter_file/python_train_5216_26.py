'''input
6
4 7 12 100 150 199
'''
import time
from sys import stdout, stdin
#initial = time.time()

def myfunction(n, arr):
	prev = arr[0]
	m = 1
	maxm = 1
	for i in range(1, n):
		if arr[i] <= 2 * prev:
			m += 1
			
		else:
			m = 1
		prev = arr[i]
		maxm = max(m, maxm)
	return maxm

n = int(stdin.readline())
arr = list(map(int, stdin.readline().split()))
m = myfunction(n, arr)
m = "%d"%(m)
stdout.write(m)

#print(time.time() - initial)