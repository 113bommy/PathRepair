import sys
import math as m
def fi():
	return sys.stdin.readline()
if __name__ == '__main__':
	n = int(fi())
	l = []
	for i in range (n):
		l.append(list(map(int, fi().split())))
	a = m.floor((l[2][0]*(l[1][0]/l[2][1]))**0.5)
	print(a,end=' ')
	for i in range(1,n):
		print(l[i][0]//a,end=' ')