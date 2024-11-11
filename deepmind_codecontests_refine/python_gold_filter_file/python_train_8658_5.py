n, l, r = map(int, input().split())

mini = 0
i = 0
ziom = 2**(l-1)
while i < n:
	mini += ziom
	if i < l - 1:
		ziom //= 2
	i += 1
maksi = 0
i = 0
ziom = 1
while i < n:
	maksi += ziom
	if i < r - 1:
		ziom *= 2
	i += 1
print(mini, maksi)