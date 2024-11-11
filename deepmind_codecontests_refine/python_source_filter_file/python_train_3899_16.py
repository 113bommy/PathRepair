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









def main():
	n,v=mi()
	arr=[0]*(3002)
	for i in range(n):
		a,b=mi()
		arr[a]=b 

	ans=0

	for i in range(1,3002):
		cantake=v 

		x=min(cantake,arr[i-1])

		cantake-=x
		ans+=x
		x=min(cantake,arr[i])
		ans+=x
		arr[i]-=x
	print(ans)
		
	


			

	

		

	













		

		


		









		



		







	

	


	
	

	




	


 
		





	

	


			









	


				


	

	
	

	




	


	




		
	












































					

if __name__ == '__main__':
	main()