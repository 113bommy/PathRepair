n,d=map(int,input().split())
li=list(map(int,input().split()))
count=0
for i in range(1,n):
	if li[i-1]>li[i]:
		j=li[i-1]-li[i]
		f=j/d
		k=j//d
		if f>=1:
			li[i]+=(k+1)*d
			count+=(k+1)
		else:
			li[i]+=d
			count+=1
	elif li[i-1]==li[i]:
		count+=1
		li[i]+=d
print(count)