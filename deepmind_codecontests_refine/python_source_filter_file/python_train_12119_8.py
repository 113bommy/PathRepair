
n=int(input())
count=0
p=0
l=list(map(int,input().split()))
for i in range(n):
	print(l[l[i]])
	if l[i]==i:
		count+=1
	elif p<2:
		if l[l[i]]==i:
			p=2
		else:
			p=1
print(count+p)
