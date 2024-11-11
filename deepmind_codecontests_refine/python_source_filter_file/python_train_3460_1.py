import sys 
try:
	sys.stdin = open('input.txt', 'r') 
	sys.stdout = open('output.txt', 'w')
except:
	pass
input = sys.stdin.readline
for tt in range(int(input())):
	# n = int(input())
	a,b,c,d = map(int,input().split())
	print(b,c,c+1)
	# l = list(map(int,input().split()))
