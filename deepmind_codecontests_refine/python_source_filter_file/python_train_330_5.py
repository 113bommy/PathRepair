# import sys
# sys.stdin=open("input1.in","r")
# sys.stdout=open("outpul.out","w")
for i in range(int(input())):
	N=int(input())
	L=list(map(int,input().split()))
	X=N//2
	X=X-1
	x=0
	if L[X]==L[X+1]:
		for j in range(X,-1,-1):
			if L[j]!=L[j-1]:
				x=j-1
				break
		X=x
	if X<5:
		print("0 0 0")
	else:
		j=1
		r=1
		while L[j]==L[j-1] and j<=X:
			r+=1
			j+=1
		g=0
		while j<=X and (g<=r or L[j]==L[j-1]):
			g+=1
			j+=1
		b=X+1-(r+g)
		if b>r:
			print(r,g,b)
		else:
			print("0 0 0")