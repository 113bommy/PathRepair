S=input()
s=0
for i in range(len(S)//2):
	if S[i] != S[-i-1]: s+=1
print(s)