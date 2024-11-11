n=int(input())
d={}
a=[]
a=[int(i) for i in input().split()]
sq=[1]
sq[0]=1
for x in range(1,31):
	sq+=[sq[x-1]*2]
a=sorted(a)	
for x in a:
	if x in d:
		d[x]+=1
		continue
	d[x]=1	
count=0
for x in a:
	for y in range(2,31):
		if (sq[y]-x) in d:
			if (sq[y]-x) is x:
				if d[(sq[y]-x)] is 1:
					continue
			count=count+1
			break


print (len(a)-count)

