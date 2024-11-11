S=input()
T=input()
result=len(T)
for s in range(0,len(S)-len(T)+1):
	diff=0
	for i in range(0,len(T)):
		if T[i]!=S[s+i]:
			diff+=1
	result=min(result,diff)

print(result)
