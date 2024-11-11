n = int(input())

answ = 0

for i in range(n):
	a = input()
	if a == "X++":
		answ += 1
	else:
		answ -= 1

print(answ)
