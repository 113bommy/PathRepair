j=input()
l=input().split()
start=0
ma=1
count=1
for i in range(len(l)-1):
	if int(l[i])==int(l[i+1]):
		if ma<count:
			ma=count+1
		count=0
	else:
		count+=1
print(max(ma,count))