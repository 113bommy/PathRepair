count = 0
n = int(input())
list1 = ['red','purple','yellow','orange','blue','green']
l = []
k=[]
for i in range(n):
	l.append(input())
for i in range(6):
	if list1[i] not in l:
		count+=1
		k.append(list1[i])
print(count)
for i in range(len(k)):
	if k[i] =='red':
		print('Reality')
	if k[i] =='purple':
		print('Power')
	if k[i] =='yellow':
		print('Mind')
	if k[i] =='orange':
		print('Soul')
	if k[i] =='green':
		print('Time')
	if k[i] =='blue':
		print('Space')
	