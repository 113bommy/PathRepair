n = int(input())
array = list(map(int, input().split()))

n1 = list()
n2 = list()
n3 = list()

for i in array:
	if i > 0:
		n1.append(i)
	elif i < 0:
		n2.append(i)
	else:
		n3.append(i)

if len(n2) % 2 == 0 and len(n2) >= 2:
	n1.append(n2[-1])
	n3.append(n2[-2])
	n2_tmp = n2[0:len(n2)-2] 
	n2 = n2_tmp[:]
	if len(n2) == 0:
		n2.append(n1[0])
		n1_tmp = n1[1:len(n1)]
		n1 = n1_tmp[:]		
else:
	n1.append(n2[-1])
	n2_tmp = n2[0:len(n2)-1]
	n2 = n2_tmp[:]
	if len(n1) > 1:
		n2.append(n1[0])
		n1_tmp = n1[1:len(n1)]
		n1 = n1_tmp[:]		

print(len(n1), end=" ")
for n in range(len(n1)):
	if n == len(n1) - 1:
		print(n1[n])
	else:
		print(n1[n], end=" ")
print(len(n2), end=" ")
for n in range(len(n2)):
	if n == len(n2) - 1:
		print(n2[n])
	else:
		print(n2[n], end=" ")
print(len(n3), end=" ")
for n in range(len(n3)):
	if n == len(n3) - 1:
		print(n3[n])
	else:
		print(n3[n], end=" ")