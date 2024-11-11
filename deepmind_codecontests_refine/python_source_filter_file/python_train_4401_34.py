import sys
# sys.stdin = open('input.txt', 'r') 
# sys.stdout = open('output.txt', 'w')
import math
import collections
from sys import stdin,stdout,setrecursionlimit
import bisect as bs
setrecursionlimit(2**20)
M = 10**9+7

def solve():
	n = int(stdin.readline())
	# n,m = list(map(int,stdin.readline().split()))
	a  = list(map(int,stdin.readline().split()))
	# q = list(map(int,stdin.readline().split()))
	# b = list(map(int,stdin.readline().split()))
	# s = stdin.readline().strip('\n')
	cnt=0
	d={}

	for i in a:
		if i not in d:
			d[i]=0
		d[i]+=1

	for i in d:
		cnt+=1

	if cnt==1:
		print("2")
	else:
		print("1")
	


t = 1
t = int(stdin.readline())
if __name__ == "__main__":
    for _ in range(t):
        solve()
    
    
# n = int(stdin.readline())
# n,m = list(map(int,stdin.readline().split()))
# h = list(map(int,stdin.readline().split()))
# q = list(map(int,stdin.readline().split()))
# b = list(map(int,stdin.readline().split()))
# s = stdin.readline().strip('\n')