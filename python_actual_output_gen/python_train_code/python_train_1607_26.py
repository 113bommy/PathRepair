n = int(input());
j=0;
while(n!=0):
	n1, n2, n3 =(map(int, input().split()))
	if ((n1==1 and n2==1) or (n2==1 and n3==1) or (n1==1 and n3==3)):
		j+=1
	n-=1
print(j)