l, r, x, y, k = map(int, input().split())

flag = True

for i in range(l, r + 1):
	if i % k == 0:
		b = i / k
		if x <= b <= y:
			flag = False
			print ("YES")
	if not flag: break

if flag:
	print("NO")
