n,x,y=[int(x) for x in input().strip().split()]
def ceil(val):
	if int(val)+1>val:
		return int(val)+1
	else:
 		return int(val)
num = ceil(n*y/100)
count = max(0,num-x)
print(count)

