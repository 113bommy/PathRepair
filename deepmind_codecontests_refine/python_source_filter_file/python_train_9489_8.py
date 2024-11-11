def func(start, end, l):
	t=-1
	for i in range(start+1, end):
		if(l[i-1]>l[i]):
			t=i
			break;
	if(t==-1):
		return(end-start)
	if(t<(end-start)/2):
		x= func(int((end+start)/2), end, l)
	else:
		x =func(start, int(((end+start)/2)), l)
	return x
n=int(input())
l=list(map(int, input().split()))
print(func(0, n,l))