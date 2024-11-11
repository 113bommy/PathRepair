s=input()
m=int(input())
f=[0]*len(s)
for i in range(len(s)-1):
	if s[i]==s[i+1]:
		f[i]=f[i-1]+1
	else:
		f[i]=f[i-1]
for i in range(m):
	l,r=[int(x) for x in input().split()]
	print(f[r-2]-f[l-2])