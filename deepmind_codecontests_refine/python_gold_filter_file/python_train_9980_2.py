from collections import defaultdict
import sys
sys.setrecursionlimit(10**6)
def ReadInput():
	return [int(i) for i in input().split(" ")]
(R, C) = ReadInput()
N = int(input())
VectorSet = set() 
Grid = defaultdict(list)
for i in range(N):
	(r, c, a) = ReadInput()
	Grid[("R", r)].append((("C", c), a))
	Grid[("C", c)].append((("R", r), a))
	VectorSet.add(("R", r))
	VectorSet.add(("C", c))
def iteration(vector):
	VectorSet.discard(vector)
	for (v, a) in Grid[vector]:
		temp = a - VectorCover[vector]
		if (v in VectorCover):
			if(temp != VectorCover[v]):
				print("No")
				exit()
		else:
			VectorCover[v] = temp
			iteration(v) 
while(len(VectorSet) != 0):
	vector = VectorSet.pop()
	VectorCover = dict() 
	VectorCover[vector] = 0
	iteration(vector)
	minR = min(a for (p, a) in VectorCover.items() if (p[0] == "R"))
	minC = min(a for (p, a) in VectorCover.items() if (p[0] == "C"))
	if (minR + minC < 0):
		print("No")
		exit()
print("Yes")