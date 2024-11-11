n = int(input())

l1 = []
l2 = []

for i in range(n):
	a,b = map(int,input().split())
	l1.append(a)
	l2.append(b)

s1 = sum(l1)
s2 = sum(l2)

flag = 0
# print(s1,s2)
if s1%2 == 1 and s2%2 == 1:

	for i in range(n):

		if l1[i]%2 == 1 and l2[i]%2 == 0:
			flag = 1
			break
		if l1[i]%2 == 0 and l2[i]%2 == 1:
			flag = 1
			break
if s1%2 == 0 and s2%2 == 0:
	print(0)
elif flag == 1:
	print(1)
elif flag == 0:
	print(-1)

