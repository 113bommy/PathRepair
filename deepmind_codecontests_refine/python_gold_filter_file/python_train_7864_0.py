# May the Speedforce be with us...
'''
problem statement achhe se padhna hai
age se bhi dekhna hai, piche se bhi dekhna hai
'''
#from math import gcd,ceil,sin,radians,cos
#from bisect import insort
#from collections import defaultdict as dd
def lcm(a,b):
	return (a*b)//gcd(a,b)
def inin():
	return int(input())
def inar():
	return list(map(int,input().split()))
def ar(element,size):
	return [element for i in range(size)]
def yes():
	print('Yes')
def no():
	print('No')
'''
def countDivisibles(A, B, M): #count numbers in the range[A,B] which are divisible by M
    if (A % M == 0): 
        return ((B // M) - (A // M)) + 1
    return ((B // M) - (A // M)) 
	
def  countSetBits(n): #count the number of set bits in the binary representation of an integer
    count = 0
    while (n): 
        count += n & 1
        n >>= 1
    return count
def digitsum(num): #return the sum of dogots of a number
	su=0
	while(num):
		su+=num%10
		num//=10
	return su
'''
def interval(i1,i2):
	return range(i1,i2+1)
Testcase=1
for _ in range(Testcase):
	n=inin()
	a=[0]+inar()
	pattern='increasing'
	if n==1:
		if a[1]==15:
			print('DOWN')
		elif a[1]==0:
			print('UP')
		else:
			print(-1)
	else:
		for i in interval(2,n):
			if a[i]>a[i-1]:
				pattern="inc"
			else:
				pattern='dec'
		if pattern=='inc':
			if a[-1]==15:
				print("DOWN")
			else:
				print('UP')
		else:
			if a[-1]==0:
				print('UP')
			else:
				print('DOWN')

	


