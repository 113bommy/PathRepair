n=int(input())
s=input()
i=1
ans=1
if s[0]=="?":
	ans=2
while(i<n-1):
	if s[i]!='?' and s[i]==s[i+1] or s[i]==s[i-1]:
		print("No")
		exit()
	if s[i]=="?":
		if i<=n-3 and s[i+1]=="?":
			if s[i-1]==s[i+2]:
				ans*=2
				i+=1
			elif s[i+2]=="?":
				ans*=2
			else:
				ans*=4
		elif s[i-1]==s[i+1]:
			ans*=2
	i+=1
if s[len(s)-1]=="?":
	ans=2
if ans>1:
	print("Yes")
else:
	print("No")

