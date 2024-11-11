T = int(input())
for case in range(T):
	#i = int(input())
	#s = input()
	m,n = [int(x) for x in input().split()]
	#ls = [int(x) for x in input().split()]
	base = ["BW" * (n//2) + "B" * (n % 2),"WB" * (n//2) + "W" * (n % 2)]
	if m % 2 == 0 and n % 2 == 0:
		base.append(base.pop(0))
	for i in range(m-1):
		print(base[i%2])
	last = base[(m-1)%2]
	if m % 2 == 0 or n % 2 == 0:
		if len(last) >= 2:
			last = last[:-1]+last[-2]
	print(last)
