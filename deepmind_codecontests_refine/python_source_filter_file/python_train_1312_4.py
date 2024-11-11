def read(is_int,split_by):
	if(is_int):
		return [int(x) for x in input().split(split_by)]
	else:
		return [x for x in input().split(split_by)]
n, k = map(int,input().split(" "))
s = input()
answer = "NO"
high = {}
low = {}
all_intersect = []
all_max = []
if k == 26:
	answer = "NO"
else:
	for i in range(n):
		if not (s[i] in low):
			low[s[i]] = i
		high[s[i]] = i
	for key in low:
		all_intersect.append(low[key])
	for key in high:
		all_intersect.append(high[key])
	all_intersect.sort()
	for i in range(len(all_intersect)):
		if all_intersect[i] in low.values():
			if all_max:
				tmp = all_max[len(all_max)-1]
				tmp += 1
				all_max.append(tmp)
			else:
				all_max.append(1)
		elif all_intersect[i] in high.values():
			tmp = all_max[len(all_max)-1]
			tmp -= 1
			all_max.append(tmp)
max_elem = max(all_max)
if max_elem > k:
	answer = "YES"
else:
	answer = "NO"
print(answer)
