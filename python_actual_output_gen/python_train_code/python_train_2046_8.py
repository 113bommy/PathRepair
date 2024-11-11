
def f(x,y):
	list=[0]
	for z in y:
		for i in range(len(list)-1,-1,-1):
			tmp=x.find(z,list[i])+1
			if tmp:
				if i+1 < len(list):
					list[i+1]=min(list[i+1],tmp)
				else:
					list.append(tmp)
	return len(list)-1
 
n=int(input())
for i in range(q):
	x=input()
	y=input()
	print(f(x,y))
