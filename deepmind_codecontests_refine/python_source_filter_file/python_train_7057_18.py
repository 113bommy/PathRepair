S=list(input())
K=int(input())
SS=S*2
F=S[1]

if len(S)==1:
	P=int(K//2)
elif S==[F]*len(S):
	P=int((len(S))*K//2)
else:
	for G in range(1,len(S)):
		if S[G-1]==S[G]:
			S[G]="O"
		else:
			continue
	A=S.count("O")
	for J in range(1,len(SS)):
		if SS[J-1]==SS[J]:
			SS[J]="O"
		else:
			continue
	B=SS.count("O")
	P=A+(B-A)*(K-1)
print(P)