k=int(input())
n=int(input())
count=0
flag=0
while n>1:
	if n%k==0:
		n//=k
		count+=1
	else:
		flag=1
		break
if flag==1:
	print("NO")
else:
	print("YES")
	print(count-1)