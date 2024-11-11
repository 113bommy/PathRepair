n = int(input())
k = input()

if int(k) < n:
	print(k)
else:
	power = 0
	digits = 0
	ans = 0
	while len(k) > 0:
		current = 0
		while(int(k[current:]) > n and current < len(k)) or (int(k[current]) == 0 and len(k) > 1 and current < len(k)-1):
			current += 1
		if current == len(k):
			power += 1
		else:
			ans += int(k[current:])*(n**power)
			power += 1
			k = str(k[:current])
	print(ans)