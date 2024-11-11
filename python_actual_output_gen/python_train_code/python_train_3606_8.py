n,a,b,c,d=map(int,input().split())
s=input()
for i in range(n-1):
	if s[i]==s[i+1]=="#":
		print("No")
		exit()
three=0
s="#"+s+"#"
for i in range(b,d+1):
	if s[i]==s[i+1]==s[i-1]==".":
		three=True
if c<d:
	print("Yes")
elif three==True:
	print("Yes")
else:
	print("No")