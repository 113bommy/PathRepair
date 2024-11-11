n = int(input())
player1 = []
player2 = []
arr = []
while n:
	n -= 1
	a = int(input())
	arr.append(a)
	if a > 0:
		player1.append(a)
	else:
		player2.append(a)
if sum(player1) != sum(player2):
	if sum(player1) > sum(player2):
		print('first')
	else:
		print('second')
elif player1 != player2:
	if player2 > player1:
		print('second')
	else:
		print('first')
else:
	if arr[-1] > 0:
		print('first')
	else:
		print('second')

