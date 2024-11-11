import sys
input=sys.stdin.buffer.readline

n,t=map(int,input().split())
if n<len(str(t)):
	print("-1")
else:
	s="1"
	for i in range(n-1):
		s+="0"
	s=int(s)
	print(s+s%t)
