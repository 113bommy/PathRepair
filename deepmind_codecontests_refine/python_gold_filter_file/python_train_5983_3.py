n,p=map(int,input().split())
l=list(input())

p-=1
k=n//2
d=[0]*(k+1)

for i in range(k):
	d[i]=min(abs(ord(l[i])-ord(l[n-i-1])),26-abs(ord(l[i])-ord(l[n-i-1])))

if p>=k:
	p=n-1-p

if sum(d)==0:
	print(0)
	exit()
i=0
j=k
while d[i]==0:
	i += 1
while d[j]==0:
	j -= 1
if i>p:
	i=p
if j<p:
	j=p
print(sum(d)+min(p-2*i+j,2*j-i-p))
