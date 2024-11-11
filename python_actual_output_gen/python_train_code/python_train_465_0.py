n=int(input())
s=input()
k=0

for i in reversed(range(1,int((n+1)/2))):
	if s[0:i]==s[i:2*i]:
		k=i
		break

print(min(n-k+1,n))