n=int(input())
s=input()
t=-1
for i in range(n-1):
	if s[i]>s[i+1]:
		t=i
		break
if t==-1:t=n-1
print(s[:i]+s[i+1:])