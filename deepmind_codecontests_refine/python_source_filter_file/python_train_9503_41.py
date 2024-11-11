import sys
import math as m
def fi():
	return sys.stdin.readline()
if __name__ == '__main__':
	n = int(fi())
	print((m.factorial(n))//(((n/2)**2)*2))