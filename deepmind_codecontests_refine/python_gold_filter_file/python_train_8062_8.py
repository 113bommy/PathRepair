n=int(input())
list=[int(i) for i in input().split()]
list.sort()
s=0
if len(list)==1:
	print(list[0])
else:
	for i in range(len(list)-1):
		s+=(i+2)*list[i]
	s+=(i+2)*list[i+1]
	print(s)