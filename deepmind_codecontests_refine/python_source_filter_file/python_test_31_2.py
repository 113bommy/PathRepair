import sys
import math
from bisect import bisect_right as br

#from statistics import mode

from itertools import combinations as cb

def int_arr(): return list(map(int, sys.stdin.readline().strip().split()))

def str_arr(): return list(map(str, sys.stdin.readline().strip().split()))

def input(): return sys.stdin.readline().strip()


#sys.stdout = open('Vupsen Pupsen and 0/output.txt', 'w')
#sys.stdin = open('Vupsen Pupsen and 0/input.txt', 'r')

for _ in range(int(input())):
	n=int(input())
	arr=int_arr()
	ans=[]
	if n%2==0:
		for i in range(0,n,2):
			if arr[i]>0 and arr[i+1]>0 or arr[i]<0 and arr[i+1]<0:
				ans.append(arr[i+1])
				ans.append(-(arr[i]))

			else:
				ans.append(abs(arr[i+1]))
				ans.append((abs(arr[i])))
		
	else:
		for i in range(0,n-3,2):
			if arr[i]>0 and arr[i+1]>0 or arr[i]<0 and arr[i+1]<0:
				ans.append(arr[i+1])
				ans.append(-(arr[i]))

			else:
				ans.append(abs(arr[i+1]))
				ans.append(abs(arr[i]))
		ans.append(arr[-1])
		ans.append(arr[-1])
		diff=arr[-3]*arr[-1]+arr[-2]*arr[-1]
		ch=-(diff//arr[-1])
		ans.append(ch)
	print(*ans)


			