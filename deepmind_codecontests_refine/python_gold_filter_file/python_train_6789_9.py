import sys
input=lambda:sys.stdin.readline().strip()
# print=lambda s:sys.stdout.write(str(s)+"\n")

for _ in range(int(input())):
	a,b=map(int,input().split())
	print(a*(len(str(b+1))-1))