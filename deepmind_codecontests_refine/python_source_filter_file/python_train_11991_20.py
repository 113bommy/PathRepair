from math import *

s=input()
t=input()

tleft=[]
tright=[]

n=len(s)
m=len(t)
j=0
i=0
while j<m:
	if s[i]==t[j]:
		tleft.append(i)
		j+=1
	i+=1

i=n-1
j=m-1
while j>=0:
	if s[i]==t[j]:
		tright.append(i)
		j-=1
	i-=1
tright.reverse()
# print(tleft,tright)
ans=[]
ans.append(max(tleft[0],tright[0]))
for i in range(1,m):
	x=max((tleft[i]-tleft[i-1]-1),(tright[i]-tright[i-1]-1))
	x=max(x,(tright[i]-tleft[i-1]-1))
	ans.append(x)

if m>1:
	ans.append(max(n-1-tleft[m-1],n-1-tright[m-1]))

print(max(ans))