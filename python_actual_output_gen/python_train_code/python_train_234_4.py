import sys
#input = sys.stdin.readline
t = int(input())
for test in range(t):
	n = int(input())
	#[n, x] = list(map(int, input().split(" ")))
	#a = list(map(int, input().split(" ")))		
	res = []
	for i in range(n):
		res.append(str(4+2*i)) 
	
	print(" ".join(res))