
n = int(input())

a = []
b = []

for i in range(0,n):
	a_i , b_i = map(int,input().split(" "))
	a.append(a_i)
	b.append(b_i)

r = int(input())

for i in b:
	if r < i:
		print(b.index(i) - 1)
		break
