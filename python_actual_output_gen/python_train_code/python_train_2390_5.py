n=int(input())
s=input()
a,b=n,0
while a<len(s):
	if s[n-1]==s[n-2]==s[n-3]:
		b+=1
	a+=n
print(b)
