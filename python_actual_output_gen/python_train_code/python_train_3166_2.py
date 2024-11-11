a=[0,0]
def ok(x,a):
	if x=='L':
		a[0]-=1
	elif x=='R':
		a[0]+=1
	elif x=='U':
		a[1]+=1
	elif x=='D':
		a[1]-=1
g=int(input())
s=input()
j=0
for i in range(len(s)):
	a=[0,0]
	for z in range(i,len(s)):
		ok(s[z],a)
		if a==[0,0]:
			j+=1
			break
print(j)
