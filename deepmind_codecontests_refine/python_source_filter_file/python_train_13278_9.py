# import sys

# sys.stdin = open("ccinput.in", "r")
# sys.stdout = open("ccoutput.out", "w")

n = int(input())
a = "I hate "
b = "I love "
c = "that "
d = "it"
x = int(n/2)
if n==1:
	print(a+d)
elif n%2 == 0:
	print((a+c), end="")
	for i in range(x-1):
		print((a+c), end="")
		print((b+c), end="")
	print(b+d)
else:
	for i in range(x):
		print((a+c), end="")
		print((b+c), end="")
	print(a+d)

