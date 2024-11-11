def check(l,temp1,temp2):
	temp3=max(temp1,temp2)
	if(l>=temp3):
		return temp1
	elif(l>=((temp1+temp2)-temp3)):
		return ((temp1+temp2)-temp3)
	else:
		return 0


if __name__ == "__main__":
	n=int(input())
	Matrix = [[0 for x in range(2)] for y in range(n)]
	for i in range(n):
		Matrix[i][0],Matrix[i][1]=(map(int,input().split()))
	l=max(Matrix[0][0],Matrix[0][1])
	for i in range(n-1):
		temp1=Matrix[i+1][0]
		temp2=Matrix[i+1][1]
		l=check(l,temp1,temp2)
		if(l==0):
			print("NO")
			exit()
	print("YES")
