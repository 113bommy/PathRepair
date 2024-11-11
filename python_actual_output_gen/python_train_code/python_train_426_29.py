a = input()
b = 1
lst = ['A','E','I','O','U','Y']
lst1= [x+1 for x,y in enumerate(a) if y in lst]
for x in range(1,len(lst1)):
	z=lst1[x]-lst1[x-1]
	if z>b: b=z
print(b)
