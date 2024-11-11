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
	n,k,x=mi()
	arr=sorted(li())
	

	tmp=[]
	last=arr[0]
	for i in range(1,n):
		if arr[i]-last>x:
			tmp.append(arr[i]-last-1)

		last=arr[i]
	tmp.sort()
	ntmp=len(tmp)
	for i in tmp:
		needk=math.floor(i/x)
		if k>=needk:
			ntmp-=1
			k-=needk 
	print(ntmp+1)



			

	

		

	













		

		


		









		



		







	

	


	
	

	




	


 
		





	

	


			









	


				


	

	
	

	




	


	




		
	












































					

if __name__ == '__main__':
	main()