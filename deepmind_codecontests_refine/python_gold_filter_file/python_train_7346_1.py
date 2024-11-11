

def main():


	n=int(input())
	sum_n=1
	op=[]
	op.append(1)

	for i in range(2,n+1):
		if sum_n+i<=n:
			op.append(i)
			sum_n+=i
		else:
			break

	diff=n-sum_n
	op[len(op)-1]+=diff

	str_op=""
	for item in op:
		str_op+=str(item)+" "

	print(len(op))
	print(str_op)
		

if __name__=="__main__":
	main()