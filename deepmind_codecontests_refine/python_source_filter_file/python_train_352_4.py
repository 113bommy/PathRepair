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
	a,b=mi()

	d1=[0]*6
	d2=[0]*6

	for i in [2,3,5]:
		if a%i==0:
			while a%i==0:
				d1[i]+=1
				a//=i

		if b%i==0:
			while b%i==0:
				d2[i]+=1
				b//=i
	cnt=0	
	if a==b:
		for i in [2,3,4]:
			x=min(d1[i],d2[i])

			cnt+=max(d1[i],d2[i])-x
	else:
		cnt=-1
	print(cnt)


			

	

		

	













		

		


		









		



		







	

	


	
	

	




	


 
		





	

	


			









	


				


	

	
	

	




	


	




		
	












































					

if __name__ == '__main__':
	main()