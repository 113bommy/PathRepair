# Problem: C. The Delivery Dilemma
# Contest: Codeforces - Codeforces Round #681 (Div. 2, based on VK Cup 2019-2020 - Final)
# URL: https://codeforces.com/contest/1443/problem/C
# Memory Limit: 256 MB
# Time Limit: 2000 ms
# 
# KAPOOR'S

from sys import stdin, stdout 

def INI():
	return int(stdin.readline())
	
def INL():
	return [int(_) for _ in stdin.readline().split()]
	
def INS():
	return stdin.readline()

def MOD():
    return pow(10,9)+7
	
def OPS(ans):
	stdout.write(str(ans)+"\n")
	
def OPL(ans):
	[stdout.write(str(_)+" ") for _ in ans]
	stdout.write("\n")

	
if __name__=="__main__":
	for _ in range(INI()):
		n=INI()
		A=INL()
		B=INL()
		X=[]
		
		for _ in range(n):
			X.append([A[_],B[_]])
		X.sort(reverse=True)
		
		s=0
		ans=0
		for _ in X:
			if s>=_[0]:
				pass
			else:
				ans+=min(_[1],_[0]-s)
				s+=min(_[1],_[0]-s)
		OPS(ans)