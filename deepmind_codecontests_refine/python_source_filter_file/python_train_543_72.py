import sys
import math

data = sys.stdin.readlines()
 
for i in range(int(data[0])):

	n = int(data[i+1])
	m = (n - 1)/2
	resp = int((8/6)*(m)*(m+1)*(2*m+1))

	print( resp )
