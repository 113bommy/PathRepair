import sys
# input = sys.stdin.buffer.readline
def I(): return(list(map(int,input().split())))
def sieve(n):
	a=[1]*n
	for i in range(2,n):
	    if a[i]:
	        for j in range(i*i,n,i):
	            a[j]=0
	return a
def solve():

	def checker(s):
		for i in range(n):
			s2=strs[i]
			c=0
			for j in range(m):
				if s2[j]!=s[j]:c+=1
				if c>1:return False
		return True
	n,m=I()
	strs=[]
	for i in range(n):
		strs.append(input())
	f=0
	for i in range(n):
		s=strs[i]
		if checker(s):
			return s
		for j in range(m):
			curr=ord(s[j])-97
			for k in range(26):
				if k==j:
					continue
				else:
					t=checker(s[:j]+chr(k+97)+s[j+1:])
					if t:
						return s[:j]+chr(k+97)+s[j+1:]
	return -1

	


for __ in range(int(input())):
	print(solve())


