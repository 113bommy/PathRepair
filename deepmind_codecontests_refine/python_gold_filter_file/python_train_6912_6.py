n=int(input())
s=input()
a,b=n,0
while a<len(s):
	if s[a-1]==s[a-2]==s[a-3]:
		b+=1
	a+=n
print(b)
