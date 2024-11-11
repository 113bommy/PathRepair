info = int(input())
data = []
for i in range(info):
	data.append([info for info in input().split(' ')])

flag = 'NO'
for i in data:
	if int(i[1]) > int(i[2]) and int(i[1]) >= 2400:
		flag = 'YES'

print(flag)
