import sys,math
from collections import deque,defaultdict
import operator as op
from functools import reduce

sys.setrecursionlimit(10**6) 

I=sys.stdin.readline

 #s="abcdefghijklmnopqrstuvwxyz"

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

def valid(row,col,rows,cols,rcross,lcross):
 	return rows[row]==0 and cols[col]==0 and rcross[col+row]==0 and lcross[col-row]==0





def main():
	ans=""
	for _ in range(ii()):
		n,k=mi()
		arr=sorted(li())
		for i in range(k):
			arr[n-1]+=arr[n-2-i]

		ans+=str(arr[n-1])+"\n"
		
	print(ans)

		
			
						
			








	





			
		



	
			





	

























	
	
	





if __name__ == '__main__':
	main()