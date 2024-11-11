s=input()

d=[0]*2019
dp=0
d[0]+=1
l=len(s)
r=1

for i in range(l):
	dp+=int(s[l-1-i])*r
	dp%=2019
	r*=10
	r%=2019
	d[dp]+=1

res=0

for a in d:
	res+=a*(a-1)//2
	
print(res)