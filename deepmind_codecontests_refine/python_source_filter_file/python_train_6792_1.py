# Problem: C. Skier
# Contest: Codeforces - Testing Round #16 (Unrated)
# URL: https://codeforces.com/problemset/problem/1351/C
# Memory Limit: 256 MB
# Time Limit: 1000 ms
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
		S=input()
		ANS=set()
		x,y=0,0
		
		ans=0
		for _ in S:
			if _=="N":
				if ((x,y),(x,y+1)) in ANS:
					ans+=1
				else:
					ans+=5
					ANS.add(((x,y),(x,y+1)))
					ANS.add(((x,y+1),(x,y)))
				y+=1
			if _=="S":
				if ((x,y),(x,y-1)) in ANS:
					ans+=1
				else:
					ans+=5
					ANS.add(((x,y),(x,y-1)))
					ANS.add(((x,y-1),(x,y)))
				y-=1
			if _=="E":
				if ((x,y),(x+1,y)) in ANS:
					ans+=1
				else:
					ans+=5
					ANS.add(((x,y),(x+1,y)))
					ANS.add(((x+1,y),(x,y)))
				x+=1
			if _=="W":
				if ((x,y),(x,y+1)) in ANS:
					ans+=1
				else:
					ans+=5
					ANS.add(((x,y),(x-1,y)))
					ANS.add(((x-1,y),(x,y)))
				x-=1
			# print(ans)
		OPS(ans)