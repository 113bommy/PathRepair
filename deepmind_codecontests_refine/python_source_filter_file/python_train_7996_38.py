S=list(input())
K=input()
for i in range(len(S)):
	if int(S[i])!=1:
		print(S[i])
		break
else:
	print(1)