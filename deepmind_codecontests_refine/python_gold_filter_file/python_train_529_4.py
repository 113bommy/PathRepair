from sys import stdin,stdout,exit
def sin(): 
	return stdin.readline().rstrip()
def listInput():
	return list(map(int,sin().split()))
def printBS(li):
	if not li: return
	for i in range(len(li)-1):
		stdout.write("%d "%(li[i]))
	stdout.write("%d\n"%(li[-1]))
n,L,a = listInput()
custs = []
for _ in range(n):
	x,y = listInput()
	custs.append((x,x+y))

custs.sort()

smokes = 0
if len(custs)==0:
	print(L//a)
elif len(custs)==1:
	print((custs[0][0])//a+(L-custs[0][1])//a)
else:
	for i in range(1,n):
		smokes+=(custs[i][0]-custs[i-1][1])//a
	smokes+=(custs[0][0])//a+(L-custs[n-1][1])//a
	print(smokes)