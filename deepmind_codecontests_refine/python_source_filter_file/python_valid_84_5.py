import sys,math
from collections import deque,defaultdict
import operator as op
from functools import reduce
from itertools import permutations
import heapq

#sys.setrecursionlimit(10**7) 
# OneDrive\Documents\codeforces

I=sys.stdin.readline

alpha="abcdefghijklmnopqrstuvwxyz"

mod=10**9 + 7

"""
x_move=[-1,0,1,0,-1,1,1,-1]
y_move=[0,1,0,-1,1,1,-1,-1]
"""
def ii():
	return int(I().strip())
def li():
	return list(map(int,I().strip().split()))
def mi():
	return map(int,I().strip().split())


def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom 

def ispali(s):
	i=0
	j=len(s)-1

	while i<j:
		if s[i]!=s[j]:
			return False
		i+=1
		j-=1
	return True



def isPrime(n):
	if n<=1:
		return False
	elif n<=2:
		return True
	else:
		
		for i in range(2,int(n**.5)+1):
			if n%i==0:
				return False
		return True

def cal(arr,x):
	n=len(arr)
	dp=[[-1 for i in range(x+1)] for j in range(n+1)]
	
	for i in range(n+1):
		dp[i][0]=0
	for i in range(1,n+1):
		for j in range(1,x+1):
			if j>=arr[i-1] and dp[i-1][j-arr[i-1]]!=-1:
				dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]]
			else:
				dp[i][j]=dp[i-1][j]
	return dp[n][x]



def main():
	ans=""
	for _ in range(ii()):
		n,s=mi()
		if n==1:
			print(0)
		elif n==1:
			print(s)
		else:
			x=math.ceil(n/2)
			print(math.floor(s/(n-x+1)))

		


		









		



		







	

	


	
	

	




	


 
		





	

	


			









	


				


	

	
	

	




	


	




		
	












































					

if __name__ == '__main__':
	main()