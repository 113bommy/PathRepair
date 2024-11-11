n=int(input())
m=list(map(int,input().split()))
a=sum(m)
i=0
l=[]
for k in m:
	l.append(5-k)
while True:
	if a/n>=4.5:
		print('0')
		exit()
	elif (a+i)/n>=4.5:
		break
	else:
		i+=1
l.sort(reverse=True)
b=0
for j in l:
	b+=l[j]
	if b>=i:
		print(j+1)
		break