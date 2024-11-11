n1 = int(input())
l1 = [[int(i) for i in input().split()] for i in range(n1)]
n2 = int(input())
l2 = [[int(i) for i in input().split()] for i in range(n2)]

dic1 = {l1[i][0]: l1[i][1] for i in range(n1)}
dic2 = {l2[i][0]: l2[i][1] for i in range(n2)}

s = 0
for i in dic1:
	if i in dic2.keys():
		if dic1.get(i) > dic2.get(i):
			s += dic1.get(i)
			dic2[i] = 0
		elif dic1.get(i) < dic2.get(i):
			s += dic2.get(i)
			dic1[i] = 0
print(sum(list(dic1.values())+list(dic2.values())))