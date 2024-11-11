list1=[]
output=[]
cases = int(input(""))
for c in range(cases):
	x,y=map(int,input().split())
	list1.append(x)
	list1.append(y)
	list1.sort()
	if list1[0] == list1[1]:
		output.append((x*2)**2)
		list1=[]
		continue 
	if list1[0]*2 <= list1[1]:
		output.append(list1[1]**2)
		list1=[]
		continue
	if list1[0]*2 > list1[1]:
		output.append((list1[0]*2)**2)
		list1=[]
print(*output, sep="\n")		
	