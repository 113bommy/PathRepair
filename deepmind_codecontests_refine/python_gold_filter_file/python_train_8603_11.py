import sys 
import math
from collections import Counter
from operator import itemgetter
import queue

def IO():
	sys.stdin=open("pyinput.txt", 'r')
	sys.stdout=open("pyoutput.txt", 'w')

def GCD(a, b):
	if(b==0): return a
	else: return GCD(b, a%b)

def LCM(a, b): return a*(b//GCD(a, b))

def scan(TYPE_1, TYPE_2=0):
	if(TYPE_1==int):
		return map(int, sys.stdin.readline().strip().split())
	elif(TYPE_1==float):
		return map(float, sys.stdin.readline().strip().split())
	elif(TYPE_1==list and TYPE_2==float):
		return list(map(float, sys.stdin.readline().strip().split()))
	elif(TYPE_1==list and TYPE_2==int):
		return list(map(int, sys.stdin.readline().strip().split()))
	elif(TYPE_1==str):
		return sys.stdin.readline().strip()
	else: print("ERROR!!!!") 



def main():
	
	n, k=scan(int)
	s=scan(str)
	st=sorted(list(set(s)))

	ans=list(s[:min(k, n)])

	if(k>n):
		print(''.join(ans), end='')
		for i in range(len(ans), k):
			print(st[0], end='')
		print()
		return

	for i in range(-1, -k-1, -1):
		ch=ord(ans[i])+1

		for ch in range(ch, 123):
			if(chr(ch) in st):
				ans[i]=chr(ch)
				print(''.join(ans))
				return
		ans[i]=st[0]




# IO()
main()