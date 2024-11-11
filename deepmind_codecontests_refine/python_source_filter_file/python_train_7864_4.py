n = int(input())
s = input()
a = s.split()
for i in range(len(a)):
	a[i] = int(a[i])

if len(a) == 1 and a[0] == 15:
	print('DOWN')
elif len(a) == 1 and a[0] == 0:
	print('UP')
elif len(a) == 1:
	print(-1)
elif a[len(a)-1] > a[len(a)-2] and a[len(a)-1] == 15:
	print('DOWN')
elif a[len(a)-1] > a[len(a)-2] and a[len(a)-1] < 15:
	print('UP')
elif a[len(a)-1] < a[len(a)-2] and a[len(a)-1] == 1:
	print('UP')
elif a[len(a)-1] < a[len(a)-2] and a[len(a)-1] > 1:
	print('DOWN')
else:
	print(-1)