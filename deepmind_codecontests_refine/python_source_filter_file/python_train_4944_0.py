n = int(input())
l1 = list(map(int, input().strip().split()))
l2 = list(map(int,input().strip().split()))

k1 = l1.pop(0)
k2 = l2.pop(0)

state = []
f = 0
while True:
	print(state, l1,l2)   
	if [l1, l2] in state:
		print(-1)
		break
	else:
		state.append([[k for k in l1], [i for i in l2]])
	if l1 == []:
		print(f, 2)
		break
	if l2 == []:
		print(f, 1)
		break
	f += 1  
	if l1[0] > l2[0]:
		l1.append(l2.pop(0))
		l1.append(l1.pop(0))
	else:
		l2.append(l1.pop(0))
		l2.append(l2.pop(0))