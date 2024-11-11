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

# mod=10**9 + 7

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



def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

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



#print("Case #"+str(_+1)+":",ans)



def main():
	n=ii()
	arr=[]
	for i in range(n):
		x,y=mi()
		arr.append((x,y))

	ans=0
	for i in range(n):
		l=0
		r=0
		u=0
		d=0
		x,y=arr[i]
		for j in range(n):
			if i!=j:
				if arr[j][0]<=x and arr[j][1]==y:
					l=1
				if arr[j][0]>=x and arr[j][1]==y:
					r=1
				if arr[j][1]<=y and arr[j][0]==x:
					u=1
				if arr[j][1]>=x and arr[j][0]==x:
					d=1
		if l==r==u==d==1:
			ans+=1
	print(ans)

	

	


	
	

	




	


 
		





	

	


			









	


				


	

	
	

	




	


	




		
	












































					

if __name__ == '__main__':
	main()