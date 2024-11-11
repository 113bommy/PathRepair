data = input().split(' ')
que_no = int(data[0])
packages = int(data[1])
distressed = 0

for i in range(0, que_no):
	que_member = input().split(' ')
	if que_member[0] == '-':
		if packages > int(que_member[1]):
			packages -= int(que_member[1])
		else:
			distressed += 1
	else:
		packages += int(que_member[1])

print('{} {}'.format(packages, distressed))
