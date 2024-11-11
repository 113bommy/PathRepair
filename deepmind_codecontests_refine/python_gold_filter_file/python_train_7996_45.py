S=list(input())
K=int(input())
for i in range(len(S))[:K]:
	if int(S[i])!=1:
		print(S[i])
		break
else:
	print(1)