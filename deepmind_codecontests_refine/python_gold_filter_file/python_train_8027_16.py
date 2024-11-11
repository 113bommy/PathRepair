if __name__ == '__main__':
	n,k = map(int, input().split())
	l = list(map(int, input().split()))
	s = sum(l)
	p = s/k
	if p != int(p):
		print('No')
	else:
		p = int(p)
		a = 0
		sum1 = 0
		flag = 1
		A = []
		b =0
		for i in range (n):
			sum1 = sum1 + l[i]
			b =b+1
			if i == n-1 and sum1 < p:
				flag = 0
				break
			if sum1 == p:
				sum1=0
				a= a+1
				A.append(b)
				b=0
			elif sum1 > p:
				flag = 0
				break
		if flag == 1:
			print('Yes')
			print(*A)
		else:
			print('No')