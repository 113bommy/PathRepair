a,b=map(int,input().split())
counter=0
for i in range(a,b):
	if str(i)==str(i)[::-1]:
		counter +=1
print(counter)