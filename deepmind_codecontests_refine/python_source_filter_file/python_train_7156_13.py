x=list(input())
l,c=len(x),False
for i in range(1,l-1):
	if(x[i-1]!=x[i]!=x[i+1] and x[i]!='.'and x[i-1]!='.'and x[i+1]!='.'):c=True
print("yes" if c else "no")
