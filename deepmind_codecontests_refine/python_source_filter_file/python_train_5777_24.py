def printanswer(answer):
	for a in answer:
		print(a, end=" ")
	print()
n = int(input())
if n==1 or n==2:
	print(1)
	print(1)
elif n==3:
	print(2)
	printanswer([1,3])
elif n==4:
	print(3)
	printanswer([1,4,2])
else:
	l = []
	for i in range(1, n+1):
		l.append(i)
	answer = [0]*n
	i = 0
	j = n-1
	current = 0
	while i <j and current<n-1 :
		answer[current] = l[i]
		answer[current+1] = l[j]
		i+=1
		j-=1
		current+=2
	if i==j:
		answer[current] = l[i]
	answer[0], answer[n-1] = answer[n-1], answer[0]
	print(len(answer))
	printanswer(answer)

