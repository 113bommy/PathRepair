t = int(input())

for _ in range(t):
	n,k = map(int,input().split())
	str1 = ''

	n1 = n-k+1
	if n1>0 and n1%2 == 1:
		print("YES")
		for i in range(k-1):
			str1+='1 '

		print(str1 + str(n1))
		continue

	n2 = n-2*(k-1)
	if n2>0 and n2%2 ==0:
		print("YES")
		for i in range(k-1):
			str1+='2 '

		print(str1 + str(n1))
		continue

	print('NO')
