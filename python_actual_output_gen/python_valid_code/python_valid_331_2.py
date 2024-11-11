# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out.py","w")
n=int(input())
a=[0]*7
for i in range(n):
	c=input()
	for i in range(7):
		print(c[i])
		a[i]+=int(c[i])
print(max(a))		