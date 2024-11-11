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
	n,m=mi()
	arr=li()

	maxi=0

	tmp=[i for i in arr]
	
	cnt=0 
	while cnt<n:
		tm=0
		idx=0
		for i in range(m):
			if tmp[i]>tm:
				tm=tmp[i]
				idx=i 
		maxi+=tm
		tmp[i]-=1
		cnt+=1



	mini=0
	arr.sort()
	i=0
	cnt=0

	while cnt<n:
		mini+=arr[i]
		arr[i]-=1
		if arr[i]==0:
			i+=1
		cnt+=1

	print(maxi,mini)





	

	


	
	

	




	


 
		





	

	


			









	


				


	

	
	

	




	


	




		
	












































					

if __name__ == '__main__':
	main()