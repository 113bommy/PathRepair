import math
import sys,collections
MAXN = 10000001

#spf = [0 for i in range(MAXN)] 
def file():
	sys.stdin = open('input.py', 'r')
	sys.stdout = open('output.py', 'w') 
def get_array():
    l=list(map(int, input().split()))
    return l
def get_2_ints():
    a,b=map(int, input().split())
    return a,b
def get_3_ints():   
    a,b,c=map(int, input().split())
    return a,b,c    	
def sieve(): 
	spf[1] = 1
	for i in range(2, MAXN): 
		spf[i] = i 
	for i in range(4, MAXN, 2): 
		spf[i] = 2

	for i in range(3, mt.ceil(mt.sqrt(MAXN))): 
		if (spf[i] == i): 
			for j in range(i * i, MAXN, i): 
				if (spf[j] == j): 
					spf[j] = i 
def getFactorization(x): 
	ret = list() 
	while (x != 1): 
		ret.append(spf[x]) 
		x = x // spf[x] 

	return ret 
def getFloor(A, x):

    (left, right) = (0, len(A) - 1)

    ind,floor = -1,-1
    while left <= right:
        mid = (left + right) // 2
        '''if A[mid] == x:
            return mid'''
        if x < A[mid]:
            right = mid - 1
        else:
            floor = A[mid]
            ind=mid
            left = mid + 1
            
    return ind
#file()
#sieve() 
mod=(10**9)+7

def main():
	#for tt in range(int(input()))
	s=input()	
	a=int(s[:-1])
	b=int(s[:-2]+s[-1])
	print(a,b)
	print(max(a,b,int(s)))
			

		





			

	























				

	















	

	










if __name__ == '__main__':
    main()