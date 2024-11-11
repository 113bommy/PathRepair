'''
unequal halves  greater half has greater ? - Monocarp
unequal halves smaller half has greater ? - 
unequal halves equal ? - Monocarp

equal halves unequal ? - Monocarp
equal halves equal ? - Bicarp
'''

n = int(input())
s = input()

left = 0
leftq = 0
for i in range(n//2):
	if s[i] == '?':
		leftq += 1
	else:
		left += int(s[i])

right = 0
rightq = 0
for i in range(n//2, n):
	if s[i] == '?':
		rightq += 1
	else:
		right += int(s[i])


if (left > right and leftq > rightq) or (right > left and rightq > leftq):
	print("Monocarp")
elif (left > right and leftq < rightq) or (right > left and rightq < leftq):
	if leftq < rightq:
		left, right = right, left
		leftq, rightq = rightq, leftq
	leftq -= rightq
	if right-left == leftq//2 * 9:
		print("Bicarp")
	else:
		print("Monocarp")
elif (left > right or right > left) and rightq == leftq:
	print("Monocarp")
elif left == right and leftq != rightq:
	print("Monocarp")
else:
	print("Bicarp")