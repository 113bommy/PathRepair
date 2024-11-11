def match(L,s):
	for i in range(0,4):
		if(s[0]==L[i][0]) or (s[1]==L[i][1]):
			return "YES"
	return "NO"

s=str(input())
L=input().split()
print(match(L,s))