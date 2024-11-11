S=list(input())
T=list(input())
cnt=0
for i in range(len(S)-len(T)):
	a=0
	for j in range(len(T)):
		if S[i+j]==T[j]:
			a+=1
	cnt=max(a,cnt)

print(len(T)-cnt)	