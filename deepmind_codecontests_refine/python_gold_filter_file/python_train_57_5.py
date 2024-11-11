# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
a = input().split()
n = int(input())
print(*a)
for i in range(n):
	b = input().split()
	a[a.index(b[0])]=b[1]
	print(*a)
