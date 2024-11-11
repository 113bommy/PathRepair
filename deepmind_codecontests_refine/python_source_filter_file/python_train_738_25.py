from math import sqrt,ceil
def f(n):
	for i in range(2,ceil(sqrt(n))):
		if n%i==0:
			return i
	return n


n = int(input())
cnt = 0

while n%2!=0:
	n -= f(n)
	cnt+=1
print(cnt+n//2)
