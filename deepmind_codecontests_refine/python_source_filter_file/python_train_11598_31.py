x=y=input();y=(y.replace('1','')).replace('4','');p=0;a=[]
if x[0] not in '14' or len(y)!=0:print('NO')
else:
	for i in x[::-1]:
		if i!='4':a.append(p);p=0
		else:p+=1
	print('NO' if max(a)>2 else 'YES')