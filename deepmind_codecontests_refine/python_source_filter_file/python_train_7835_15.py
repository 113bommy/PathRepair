# your code goes here
# your code goes here
# your code goes here
testcases=int(input())
while(testcases):
	size=int(input())
	array=map(int,input().split())
	neglist=[]
	poslist=[]
	reslist=[]
	for val in array:
		if val<0:
			neglist.append(val)
		else:
			poslist.append(val)
	psumval=sum(poslist)
	nsumval=sum(neglist)
	if(abs(psumval)==abs(nsumval)):
		print("NO")
	else:
		print("YES")
		if(abs(psumval)>abs(nsumval)):
			reslist.extend(reversed(poslist))
			for val in neglist:
				if psumval+val!=0:
					reslist.append(val)
					neglist.remove(val)
					psumval+=val
				if(len(neglist)==0):
					break
			reslist.extend(neglist)
		else:
			reslist.extend((neglist))
			for val in poslist:
				if nsumval+val!=0:
					reslist.append(val)
					poslist.remove(val)
					nsumval+=val
				if(len(poslist)==0):
					break
			reslist.extend(poslist)
		stri=''
		for val in reslist:
			stri+=str(val)+' '
		print(stri)
	testcases-=1