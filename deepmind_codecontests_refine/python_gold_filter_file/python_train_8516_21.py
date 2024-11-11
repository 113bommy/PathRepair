import sys
read = sys.stdin.buffer.read
input = sys.stdin.readline
input = sys.stdin.buffer.readline

#sys.setrecursionlimit(10**9)
#from functools import lru_cache

def RD(): return sys.stdin.read()
def II(): return int(input())
def MI(): return map(int,input().split())
def MF(): return map(float,input().split())
def LI(): return list(map(int,input().split()))
def LF(): return list(map(float,input().split()))
def TI(): return tuple(map(int,input().split()))
# rstrip().decode('utf-8')

def main():
	n=II()
	s=input().rstrip().decode()
	li=[0]*n
	for i in range(n):
		if s[i]=="D":
			li[i]=1
		elif s[i]=="M":
			li[i]=2
		elif s[i]=="C":
			li[i]=3
	
	q=II()
	K=LI()
	for k in K:
		D=0
		M=0
		DM=0
		ans=0
		
		for i in range(n):
			if li[i]==1:
				D+=1
			elif li[i]==2:
				M+=1
				DM+=D
			elif li[i]==3:
				ans+=DM
			
			if i-k+1>=0:
				if li[i-k+1]==1:
					D-=1
					DM-=M
				elif li[i-k+1]==2:
					M-=1
		print(ans)
		


if __name__ == "__main__":
	main()
