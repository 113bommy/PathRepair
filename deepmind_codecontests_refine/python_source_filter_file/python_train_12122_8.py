n, b = [int(x) for x in input().split()];lights_order = [int(x) for x in input().split()]
prev_light = n
arr = [n] * n
for light in lights_order:
	if(light < prev_light):
		arr[light-1:prev_light] = [light]*(prev_light-light+1)
		prev_light = light-1
	if(light == 1):
		break
print(*arr)