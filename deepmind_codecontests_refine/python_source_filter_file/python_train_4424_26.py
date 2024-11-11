from math import *
from copy import *
from string import *				# alpha = ascii_lowercase
from random import *
from sys import stdin
from sys import maxsize
from operator import *				# d = sorted(d.items(), key=itemgetter(1))
from itertools import *
from collections import Counter		# d = dict(Counter(l))
import math

def bin1(l,r,k,t,b,val,ans):
	if(l>r):
		return ans
	else:
		mid=(l+r)//2
		v=k**mid
		if(v==val):
			return v
		elif(v>val):
			ans=mid
			return bin1(mid+1,r,k,t,b,val,ans)
		else:
			return bin1(l,mid-1,k,t,b,val,ans)
		
def bin2(l,r,k,t,b,val,ans):
	if(l>r):
		return ans
	else:
		mid=(l+r)//2
		v=t*(k**mid)+b*(mid)
		if(v==val):
			return v
		elif(v>val):
			ans=mid
			return bin2(l,mid-1,k,t,b,val,ans)
		else:
			return bin2(mid+1,r,k,t,b,val,ans)

def SieveOfEratosthenes(n): 
      
    # Create a boolean array "prime[0..n]" and initialize 
    #  all entries it as true. A value in prime[i] will 
    # finally be false if i is Not a prime, else true. 
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
          
        # If prime[p] is not changed, then it is a prime 
        if (prime[p] == True): 
              
            # Update all multiples of p 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
    l=[]
    for i in range(2,n+1):
    	if(prime[i]):
    		l.append(i)
    return l
def bin(l,r,ll,val):
	if(l>r):
		return -1
	else:
		mid=(l+r)//2
		if(val>=ll[mid][0] and val<=ll[mid][1]):
			return mid
		elif(val<ll[mid][0]):
			return bin(l,mid-1,ll,val)
		else:
			return bin(mid+1,r,ll,val)
def deci(n):
	s=""
	while(n!=0):
		if(n%2==0):
			n=n//2
			s="0"+s
		else:
			n=n//2
			s="1"+s
	return s
def diff(s1,s2):
	if(len(s1)<len(s2)):
		v=len(s1)
		while(v!=len(s2)):
			s1="0"+s1
			v=v+1
	else:
		v=len(s2)
		while(v!=len(s1)):
			s2="0"+s2
			v=v+1
	c=0
	for i in range(len(s1)):
		if(s1[i:i+1]!=s2[i:i+1]):
			c=c+1
	return c
from sys import stdin, stdout 
def fac(a,b):
	v=a
	while(a!=b):
		v*=a-1
		a=a-1
	return v
def bino(l,r,n):
	if(l>r):
		return -1
	else:
		mid=(l+r)//2
		val1=math.log((n/mid)+1,2)
		val2=int(val1)
		if(val1==val2):
			return val1
		elif(val1<1.0):
			return bino(l,mid-1,n)
		else:
			return bino(mid+1,r,n)

def binary(l,r,ll,val,ans):
	if(l>r):
		return ans
	else:
		mid=(l+r)//2
		if(ll[mid]==val):
			return ll[mid]
		elif(ll[mid]<val):
			ans=ll[mid]
			return binary(mid+1,r,ll,val,ans)
		else:
			return binary(l,mid-1,ll,val,ans)
def check(n):
	v=1
	while(n!=0):
		if(n%10==0 or n%10==1):
			n=n//10
		else:
			v=0
			break
	return v
def stairs(n,m,val,c,l):
	if(val>n):
		return 100000
	elif(val==n):
		if(l[val]!=-1):
			return l[val]
		elif(c%m==0):
			l[val]=c
			return l[val];
		else:
			l[val]=100000
			return l[val]
	else:
		# if(l[val]!=-1):
		# 	return l[val]
		# else:
		l[val]=min(stairs(n,m,val+1,c+1,l),stairs(n,m,val+2,c+1,l))
		return l[val]

if __name__ == '__main__':
	s=str(input())
	s1="CODEFORCES"
	if(len(s)<len(s1)):
		print("NO")
	else:
		if(s[0:4]=="CODE" and s[len(s)-6:]=="FORCES" or s[0:10]==s1 or s[len(s)-10:]==s1 or s[0:1]=="C" and s[len(s)-9:]=="ODEFORCES" or s[0:2]=="CO" and s[len(s)-8:]=="DEFORCES" or s[0:3]=="COD" and s[len(s)-7:]=="EFORCES" or s[0:5]=="CODEF" and s[len(s)-5:]=="ORCES" or s[0:6]=="CODEFO" and s[len(s)-4:]=="RCES" or s[0:7]=="CODEFOR" and s[len(s)-3:]=="CES" or s[0:8]=="CODEFORC" and s[len(s)-2:]=="ES" or s[0:6]=="CODEFORCE" and s[len(s)-1:]=="S"):
			print("YES")
		else:
			print("NO")