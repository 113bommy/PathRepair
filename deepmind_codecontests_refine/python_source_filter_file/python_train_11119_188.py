n=[]
for i in range(6):
	n.append(int(input()))
print('Yay!' if n[4] - n[0] < n[5] else ':(')