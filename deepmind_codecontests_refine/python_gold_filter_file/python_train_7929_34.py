def choose(a, b):
	flag = 0
	for i in a:
		for j in b:
			if i+j not in a and i+j not in b:
				flag = 1
				print(i, j)
				break
		if flag:
			break

n1 = int(input())
a = list(map(int, input().split()))
n2 = int(input())
b = list(map(int, input().split()))

choose(a, b)