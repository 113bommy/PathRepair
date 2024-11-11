
n=int(input())

str1=input()

x=(n-11)//2
l=list(str1)


s=l.count('8')
if(s<=x):
	print("NO")
else:
	count=0
	for i in range(x*2+1):
		if(str1[i]=='8'):
			count=count+1
	if(count>=s):
		print("YES")
	else:
		print("NO")

