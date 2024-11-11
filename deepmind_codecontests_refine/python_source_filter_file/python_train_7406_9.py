m=int(input())
a=list(map(int,input().split()))
s=0
e=0
i=0
j=0
ma=0
if(a[0]==1):
	while( i<len(a) and a[i]==1 ):
		if(a[i]==1):
			s+=1
		i+=1
	ma=s

while(i<len(a)):
	if(i==len(a)-1):
		if(a[i]==1):
			j+=1
			e=j
			if(j>ma):
				ma=j
		
	if(a[i]==1):
		j+=1
	else:
		if(j>ma):
			ma=j
		j=0
	i+=1
if(ma==e):
	print(e+s)
else:
	print(ma)

