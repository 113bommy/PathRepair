n,k=map(int,input().split())
s=input()
l=input().split()
count=0
total=0
for i in s:
	if i in l:
		count+=1
	else:
		total=total+(count*(count+1))//2
		count=0
	total=total+(count*(count+1))//2
print(total)