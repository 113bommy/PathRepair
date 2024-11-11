n = 6
table = []
ans = []
for i in range(n):
	s = input()
	table.append(s)

ind = 0
if table[0][3] == '.':
	ans.append(table[0][:3] + 'P' + table[0][4:])
	ind = 1
elif table[0][4] == '.':
	ans.append(table[0][:4] + 'P' + table[0][5:])
	ind = 1
elif table[1][3] == '.':
	ans.append(table[0])
	ans.append(table[1][:3] + 'P' + table[1][4:])
	ind = 2
elif table[1][4] == '.':
	ans.append(table[0])
	ans.append(table[1][:4] + 'P' + table[1][5:])
	ind = 2


elif table[0][0] == '.':
	ans.append('P' + table[0][1:])
	ind = 1
elif table[0][1] == '.':
	ans.append(table[0][:1] + 'P' + table[0][2:])
	ind = 1
elif table[0][6] == '.':
	ans.append(table[0][:6] +'P' + table[0][7:])
	ind = 1
elif table[0][7] == '.':
	ans.append(table[0][:7] +'P')
	ind = 1

elif table[1][0] == '.':
	ans.append(table[0])
	ans.append('P' + table[1][1:])
	ind = 2
elif table[1][1] == '.':
	ans.append(table[0])
	ans.append(table[1][:1] + 'P' + table[1][2:])
	ind = 2
elif table[1][6] == '.':
	ans.append(table[0])
	ans.append(table[1][:6] +'P' + table[1][7:])
	ind = 2
elif table[1][7] == '.':
	ans.append(table[0])
	ans.append(table[1][:7] +'P')
	ind = 2


elif table[2][3] == '.':
	ans.append(table[0])
	ans.append(table[1])
	ans.append(table[2][:3] + 'P' + table[2][4:])
	ind = 3
elif table[2][4] == '.':
	ans.append(table[0])
	ans.append(table[1])
	ans.append(table[2][:4] + 'P' + table[2][5:])
	ind = 3
elif table[3][3] == '.':
	ans.append(table[0])
	ans.append(table[1])
	ans.append(table[2])
	ans.append(table[3][:3] + 'P' + table[3][4:])
	ind = 4
elif table[3][4] == '.':
	ans.append(table[0])
	ans.append(table[1])
	ans.append(table[2])
	ans.append(table[3][:4] + 'P' + table[3][5:])
	ind = 4

elif table[2][0] == '.':
	ans.append(table[0])
	ans.append(table[1])
	ans.append('P' + table[2][1:])
	ind = 3
elif table[2][1] == '.':
	ans.append(table[0])
	ans.append(table[1])
	ans.append(table[2][:1] + 'P' + table[2][2:])
	ind = 3
elif table[2][6] == '.':
	ans.append(table[0])
	ans.append(table[1])
	ans.append(table[2][:6] +'P' + table[2][7:])
	ind = 3
elif table[2][7] == '.':
	ans.append(table[0])
	ans.append(table[1])
	ans.append(table[2][:7] +'P')
	ind = 3

elif table[3][0] == '.':
	for i in range(0, 3):
		ans.append(table[i])
	ans.append('P' + table[3][1:])
	ind = 4
elif table[3][1] == '.':
	for i in range(0, 3):
		ans.append(table[i])
	ans.append(table[3][:1] + 'P' + table[3][2:])
	ind = 4
elif table[3][6] == '.':
	for i in range(0, 3):
		ans.append(table[i])
	ans.append(table[3][:6] +'P' + table[3][7:])
	ind = 4
elif table[3][7] == '.':
	for i in range(0, 3):
		ans.append(table[i])
	ans.append(table[3][:7] +'P')
	ind = 4

elif table[4][3] == '.':
	for i in range(0, 4):
		ans.append(table[i])
	ans.append(table[4][:3] + 'P' + table[4][4:])
	ind = 5
elif table[4][4] == '.':
	for i in range(0, 4):
		ans.append(table[i])
	ans.append(table[4][:4] + 'P' + table[4][5:])
	ind = 5
elif table[5][3] == '.':
	for i in range(0, 5):
		ans.append(table[i])
	ans.append(table[5][:3] + 'P' + table[5][4:])
	ind = 6
elif table[5][4] == '.':
	for i in range(0, 5):
		ans.append(table[i])
	ans.append(table[5][:4] + 'P' + table[5][5:])
	ind = 6
	

	
elif table[4][0] == '.':
	for i in range(0, 4):
		ans.append(table[i])
	ans.append('P' + table[4][1:])
	ind = 5
elif table[4][1] == '.':
	for i in range(0, 4):
		ans.append(table[i])
	ans.append(table[4][:1] + 'P' + table[4][2:])
	ind = 5
elif table[4][6] == '.':
	for i in range(0, 4):
		ans.append(table[i])
	ans.append(table[4][:6] +'P' + table[4][7:])
	ind = 5
elif table[4][7] == '.':
	for i in range(0, 4):
		ans.append(table[i])
	ans.append(table[4][:7] +'P')
	ind = 5

elif table[5][0] == '.':
	for i in range(0, 5):
		ans.append(table[i])
	ans.append('P' + table[5][1:])
	ind = 6
elif table[5][1] == '.':
	for i in range(0, 5):
		ans.append(table[i])
	ans.append(table[5][:1] + 'P' + table[5][2:])
	ind = 6
elif table[5][6] == '.':
	for i in range(0, 5):
		ans.append(table[i])
	ans.append(table[5][:6] +'P' + table[5][7:])
	ind = 6
elif table[5][7] == '.':
	for i in range(0, 5):
		ans.append(table[i])
	ans.append(table[5][:7] +'P')
	ind = 6

for i in range(ind, n):
	ans.append(table[i])

for i in ans:
	print(i)