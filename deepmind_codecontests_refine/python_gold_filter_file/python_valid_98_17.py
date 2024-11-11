from sys import stdin, stdout 
import sys
import math
import itertools
from collections import defaultdict
sys.setrecursionlimit(10**6)


def main(): 
	t = int(stdin.readline().strip())
	for j in range (1,t+1):
		n = int(stdin.readline().strip())
		s = stdin.readline().strip()
		flag = 1
		for i in range(n-1):
			if s[i] != s[i+1]:
				print(i+1,i+2)
				flag = 0
				break
		if flag:
			print(-1,-1)

if __name__ == "__main__": 
	main()	 	 
