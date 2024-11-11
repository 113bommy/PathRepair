from sys import stdin,stdout
input = stdin.readline
def write(n,sep="\n"):
	stdout.write(str(n))
	stdout.write(sep)
def gil():
	return list(map(int, input().split()))
	
n = int(input())
if n <= 2:
	print(-1)
else:
	p = list(range(n))
	print(*p)
	print(*p)
	for i in range(n):
		print((i*2)%n, end = " ")
	print()
