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
	s=I().strip()
	nb,ns,nc=mi()
	pb,ps,pc=mi()
	r=ii()
	bread=s.count("B")
	souce=s.count("S")
	chese=s.count("C")
	def possi(burger):

		need_bread=max(0,(burger*bread)-nb)
		need_souce=max(0,(burger*souce)-ns)
		need_chese=max(0,(burger*chese)-nc)

		need_money=(need_bread*pb) + (need_souce*ps)+ (need_chese*pc)

		if need_money<=r:
			return True
		return False
	i=0
	j=10**12
	ans=0
	while i<=j:
		mid=i+(j-i)//2
		if possi(mid):
			ans=max(ans,mid)
			i=mid+1
		else:
			j=mid-1
	print(ans)
	
			

	

		

	













		

		


		









		



		







	

	


	
	

	




	


 
		





	

	


			









	


				


	

	
	

	




	


	




		
	












































					

if __name__ == '__main__':
	main()