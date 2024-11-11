n = int(input())
a = []
s = input()
a = s.split()
for i in range(len(a)):
	a[i] = int(a[i])
	
sum = 1
height = 1
mh = height
while len(a)>1:
	if a[0]>=a[1]:
		a.remove(a[0])
		height += 1
		if height > mh: mh = height
	else:
		a.remove(a[0])
		sum += 1
		height = 1
		
print(mh, end = ' ')
print(sum)