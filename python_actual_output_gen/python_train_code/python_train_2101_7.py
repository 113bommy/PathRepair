n = int(input())
result = list()
result.append(["polycarp"])
for i in range(n):
	length = len(result)
	s = input().split()
	s0 = s[0].lower()
	s2 = s[2].lower()
	for i in range(length-1):
		if s2 in result[i] and s0 not in result[i+1]:
			result[i+1].append(s2)
	if s2 in result[length-1]:
		result.append([s0])
length = len(result)
print(length)
