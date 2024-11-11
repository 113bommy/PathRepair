import sys,math
from collections import deque,defaultdict
import operator as op
from functools import reduce

#sys.setrecursionlimit(10**6) 

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

"""def ncr(n, r):
    r = min(r, n-r)
    numer = (reduce(op.mul, range(n, n-r, -1), 1))%(10**9+7)
    denom = (reduce(op.mul, range(1, r+1), 1))%(10**9+7)
    return (numer // denom)%(10**9+7)"""
def ncr(n, r, p):
    # initialize numerator
    # and denominator
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den, 
            p - 2, p)) % p
 

def gcd(x, y):
    while y:
        x, y = y, x % y
    return x

def valid(row,col,rows,cols,rcross,lcross):
 	return rows[row]==0 and cols[col]==0 and rcross[col+row]==0 and lcross[col-row]==0


def div(n):
	tmp=[]
	for i in range(2,int(n**.5)+1):
		if n%i==0:
			cnt=0
			while(n%i==0):
				n=n//i 
				cnt+=1
			tmp.append((i,cnt))
	if n>1:
		tmp.append((n,1))
	return tmp

def isPrime(n):
	if n<=1:
		return False
	elif n<=2:
		return True
	else:
		flag=True
		for i in range(2,int(n**.5)+1):
			if n%i==0:
				flag=False
				break
		return flag

def s(b):
	ans=[]
	while b>0:
		tmp=b%10
		ans.append(tmp)
		b=b//10
	return ans


def main():
	s=I().strip()
	last1=math.inf
	cnt4=0
	flag=0
	for i in range(len(s)):
		if s[i]=="1":
			last1=i
		elif s[i]=="4":
			if i-last1<=2:
				flag=1
				break
		else:
			flag=1
			break
	if flag:
		print("NO")
	else:
		print("YES")
	








	



	
		




	










	


	

	

		



		

		
		


	
	

		
	

		




		




			












			
		
			



		


	
			
						
			








	





			
		



	
			





	

























	
	
	





if __name__ == '__main__':
	main()