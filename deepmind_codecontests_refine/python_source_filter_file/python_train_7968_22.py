def run():
	import sys
	sys.stdin = open('/home/punit/Documents/Cpp Programs/input.txt', 'r')
	sys.stdout = open('/home/punit/Documents/Cpp Programs/output.txt', 'w') 
	from math import ceil,sqrt,floor
 
# run()
from math import ceil,sqrt,floor

n = int(input())

if(n<3):
	print(-1)
elif(n%2):
	n = n*n
	print((n+1)//2,(n-1)//2)
else:
	n = n*n
	print((n+4)//4,(n-4)//2)