# May the Speedforce be with us...
'''
for _ in range(int(input())):
arr=list(map(int,input().split()))
n,k=map(int,input().split())
n=int(input())
s=input()

from collections import defaultdict
d=defaultdict()

d=dict()
s=set()
s.intersection()
s.union()
s.difference()


problem statement achhe se padhna hai
age se bhi dekhna hai, piche se bhi dekhna hai
'''
#from math import gcd,ceil,sin,radians,cos
#from bisect import insort
from collections import defaultdict as dd
def lcm(a,b):
	return (a*b)//gcd(a,b)
def inin():
	return int(input())
def inar():
	return list(map(int,input().split()))
def ar(element,size):
	return [element for i in range(size)]
def digitsum(num): #return the sum of dogots of a number
	su=0
	while(num):
		su+=num%10
		num//=10
	return su
def yes():
	print('YES')
def no():
	print('NO')

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




Testcase=1
for _ in range(Testcase):
	n,m=inar()
	if min(n,m)%2:
		print('Akshat')
	else:
		print("Malvika")