n,*l=map(int,open(0).read().split())
o=t=f=0
for i in l:
	if i%4==0:f+=1
	elif i%2==0:t+=1
	else:o+=1
print("YNeos"[(t==1)+o>f+1::2])