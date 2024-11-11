temp = list('qwertyuiop')
temp1 = list('asdfdghjkl;')
temp2 = list('zxcvbnm,./')
direct = input()
data = input()
temps = list()
for i in range(len(data)):
	if data[i] in temp:
		temps.append(temp[temp.index(data[i]) + (-1 if direct == 'R' else 1)])
	elif data[i] in temp1:
		temps.append(temp1[temp1.index(data[i]) + (-1 if direct == 'R' else 1)])
	elif data[i] in temp2:
		temps.append(temp2[temp2.index(data[i]) + (-1 if direct == 'R' else 1)])
print(''.join(temps))