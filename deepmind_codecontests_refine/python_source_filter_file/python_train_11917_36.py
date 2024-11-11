li=[1]
x=1
for i in range(1,500):
	x+=1
	li.append(li[i-1]+x)
n=int(input())
cnt=0
for i in range(500):
	n-=li[i]
	cnt+=1
	if n==0 or n<li[i]:
		break
print(cnt)