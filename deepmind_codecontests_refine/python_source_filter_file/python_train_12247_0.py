n,d=map(int,input().split())
s=list(input())
k,m,flag=0,0,0
x=[]
for i in range(n):
	if s[i]=='1':
		x.append(i)
li=len(x)
print(x)
while k<=li-2:
	if x[k+1]-x[k]>d:
		flag=1
		break
	else:
		temp=k+1
		while temp<li and x[temp]-x[k]<=d:
			temp+=1
			# print(temp)
		m+=1
		# print(k,temp,m)
		k=temp-1
		# print(k,temp)

if flag==0:
	print(m)
else:
	print(-1)