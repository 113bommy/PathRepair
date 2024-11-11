import re, math, decimal, bisect
def read(): return input().strip()
def iread(): return int(input().strip())
def viread(): return [int(_) for _ in input().strip().split()]

# code goes here
n, m = viread()
items = []
remain = viread()
cost = viread()
for i in range(n):
	items.append([cost[i], i+1, remain[i]])
items.sort()
# for item in items:
# 		print(*item)
idx = [0]*(n+1)
# for i in range(n):
# 	idx[items[i][1]] = i
# print(idx)

canpick = n
firstnonempty = 0
for i in range(m):
	# print("------------------")
	t, d = viread()
	# print("I'd like {} of #{}".format(d, t))
	cost = 0
	target = items[idx[t]]
	# for item in items:
	# 	print(*item, "+" if item is target else "")
	if target[2] >= d:
		target[2] -= d
		cost += d * target[0]
		if target[2] == 0:
			canpick -= 1
	else:
		if target[2] != 0:
			canpick -= 1
		cost += target[2] * target[0]
		d -= target[2]
		target[2] = 0
		nxt = firstnonempty
		# print("Not enough! {}".format(cost))
		while d > 0 and canpick > 0 and nxt <= n:
			# print("Try {}".format(items[nxt][1]))
			if items[nxt][2] == 0:
				# print("Already empty")
				nxt += 1
			elif items[nxt][2] >= d:
				items[nxt][2] -= d
				cost += d * items[nxt][0]
				d = 0
				if items[nxt][2] == 0:
					canpick -= 1
					nxt += 1
			else:
				cost += items[nxt][2] * items[nxt][0]
				d -= items[nxt][2]
				items[nxt][2] = 0
				canpick -= 1
				nxt += 1
				# print("Not enough {}! {}".format(nxt+1, cost))
		# print(d, canpick, nxt, n)
		if d != 0:
			# print("There's not enough!!")
			cost = 0
		firstnonempty = nxt
	print(cost)

