z = []
t = 0
flag = 0
r = 0
x,y = map(int,input().split())
for i in range(x):
	# a = input()
	z.append(input())
# print(len(z[0]))
for j in range(len(z)):
	for k in range((y)):
		if z[j][k] == "B":
			t = t + 1
			# print(t,k)
		elif z[j][k] == "W" and t!=0 :
			flag = 1
			k = k - 1
			break
		if t == len(z[j]) and t!= 0:
			flag = 1
			break
	if flag == 1:
		break
print(j+int((t-1)/2)+1,k-int((t-3)/2))