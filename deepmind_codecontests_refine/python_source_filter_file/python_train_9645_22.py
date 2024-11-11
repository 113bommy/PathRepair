t=int(input())

s1=list(map(int,input().split()))

myset = set(s1)


l=len(myset)


if(0 in myset):
	l=l-1;


if(l>2):
	print(3)
elif(l==2):
	print(2)
elif(l==1):
	print(1)			