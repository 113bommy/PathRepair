import itertools

n=int(input());
flag=1;
lst = [list(i) for i in itertools.product([0, 1], repeat=n)]

angles=[];

for i in range(n):
	angles.append(int(input()));

#print(lst)

for i in lst:
	s=0
	#print(i)
	for j in range(n):
		if(i[j]==0):
			s-=angles[j];
		else:
			s+=angles[j];
		
	if(s==0 or s==360):
		flag=0;
		break;
	#print(s)

if(flag==1):
	print("no");
else:
	print("yes")