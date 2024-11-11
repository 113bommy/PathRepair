w=input().split(" ")
n=int(w[0])
dur=int(w[1])
w2=input().split(" ")
arr=[]
for i in range(n):
	arr.append(int(w2[i]))
devu=sum(arr)
if dur< (((n-1)*5) + devu):
	print("-1")
else:
	k=(dur-devu)/5
	m=(dur-devu)//5
	if k==m:
		print(m)
	else:
		print("-1")