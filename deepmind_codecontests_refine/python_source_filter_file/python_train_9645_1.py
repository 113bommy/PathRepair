# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n=int(input())
a=set(map(int,input().split()))
if '0' in a:
	print(len(s)-1)
else:
	print(len(a))	