left = 0
right = 0
n = input()
l = len(n)
fulcrum = n.find('^')
left_half = n[0:fulcrum]
right_half = n[(fulcrum+1):l]
#print(left_half)
#print(right_half)
left_half = left_half[::-1]
for i in range(len(left_half)):
	if left_half[i].isalnum():
		left = left + (int(left_half[i])*(i+1))
for j in range(len(right_half)):
	if right_half[j].isalnum():
		right = right + (int(right_half[j])*(j+1))
if left == right:
	print('balance')
elif left<right:
	print('right')
else:
	print('left')