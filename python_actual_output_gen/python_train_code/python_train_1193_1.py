for _ in range(int(input())):
	act, pl = map(int, input().split())
	m = input().strip("0")
	le = len(m)
	if not le:
		print(0)
		continue
	act_cost = 0
	pl_cost = 0
	new = True
	i = 0
	while i < le:
		if new:
			act_cost += act
			new = False
		while i < le and m[i] == "1":
			i += 1
		while i < le and m[i] == "0":
			pl_cost += pl
			i += 1
		if pl_cost and pl_cost < act_cost:
			act_cost += pl_cost
		else:
			new = True
		pl_cost = 0
	print(act_cost)