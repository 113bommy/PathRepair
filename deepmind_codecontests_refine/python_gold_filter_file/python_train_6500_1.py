n=int(input())
array=list(map(int,input().split()))
prefixArray_Ordinary=[]
prefix=0
for i in array:
	prefix+=i
	prefixArray_Ordinary.append(prefix)

array.sort()
prefixArray_Sorted=[]
prefix=0
for i in array:
	prefix+=i
	prefixArray_Sorted.append(prefix)

#print(prefixArray_Sorted)
#print(prefixArray_Ordinary)
for query in range(int(input())):
	what,l,r=list(map(int,input().split()))
	l-=1
	r-=1
	if what==1:
		if l==0:
			print(prefixArray_Ordinary[r])
		else:
			print(prefixArray_Ordinary[r]-prefixArray_Ordinary[max(0,l-1)])
	else:
		if l==0:
			print(prefixArray_Sorted[r])
		else:
			print(prefixArray_Sorted[r]-prefixArray_Sorted[max(0,l-1)])

