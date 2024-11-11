import sys
input = sys.stdin.readline

n=int(input())
s=input().rsplit()[0]

def calc(k):
	D=M=DM=DMC=0
	for i in range(n):
		if k<=i:
			if s[i-k]=="D":
				D-=1
				DM-=M
			elif s[i-k]=="M":
				M-=1
		if s[i]=="D":
			D+=1
		elif s[i]=="M":
			M+=1
			DM+=D
		elif s[i]=="C":
			DMC+=DM
	return DMC

q=int(input())
*k,=map(int,input().split())
ans=[calc(x) for x in k]
print(*ans,sep="\n")