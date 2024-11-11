n = input()
data = input()

out = [0] * 10

for i in range(len(data)):


	if (data[i] == 'L'):
		for j in range(0, 10, 1):
			if (out[j] == 0):
				out[j] = 1
				break
	elif (data[i] == 'R'):
		for k in range(9, -1, -1):
			if (out[k]== 0):
				out[k] = 1
				break
	else:
		out[int(data[i])] = 0
	#print (str(data[i]) + " "+ str(out))
for x in out:
	print(x, end = '')
			