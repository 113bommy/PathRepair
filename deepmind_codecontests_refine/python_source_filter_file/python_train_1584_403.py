x=int(input())
flag=0
i=4
while flag==0:
	l=x+i
	if (l-1)%6!=0 and (l+1)%6!=0 and (i-1)%6!=0 and (i+1)%6!=0:
			flag+=1
	else:
		i+=1

print(i," ",l)


