n=int(input())
l=list(map(int,input().split()))
sh=0
sv=0
s=0
l.sort()
a=[]
i=len(l)-1
j=0
while i >= j:
	a.append(l[i])
	a.append(l[j])
	if i==j:
		a.append(l[i])
	i-=1
	j+=1
for i in range(0,len(l),2):
	sh+=a[i]
for j in range(1,len(l),2):
	sv+=a[j]
s=sh**2+sv**2
print(s)
