# import sys 
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w+')
mod = int(1e9)+7
def ip():
	return int(input())
def Ip():
	return map(int, input().split())
from math import pow
for _ in range (0, int(input())):
	n = ip()
	if n==2:
		print(1)
	else:
		a,b = 0,pow(2,n)
		for i in range (1,n//2):
			b += pow(2,i)
		for i in range (n//2,n):
			a += pow(2,i)
		print(int(abs(a-b)))
		# print (a,b)