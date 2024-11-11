string=input()
array=[0 for i in range(len(string))]
for i in range(1,len(string)):
	#print(array)
	array[i]=array[i-1]
	if string[i]==string[i-1]:
		array[i]+=1
	
#print(array)
for i in range(int(input())):
	a,b=list(map(int,input().split()))
	a-=1
	b-=1
	print(array[b]-array[a])
