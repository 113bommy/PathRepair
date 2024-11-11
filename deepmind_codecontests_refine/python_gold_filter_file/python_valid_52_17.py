def merge(l, r):	
	result = []
	n = len(l)
	m = len(r)
	i = 0
	j = 0
	while i < n and j < m:
		if l[i] <= r[j]:
			result.append(l[i])
			i += 1
		else:
			result.append(r[j])
			j += 1
	
	while i < n: 
		result.append(l[i])
		i += 1

	while j < m:
		 result.append(r[j])
		 j += 1
	return result


def mergesort(list):
	n = len(list)
	if n==1: return list #list sorted
	mid = n // 2
	left_list = mergesort(list[:mid])
	right_list = mergesort(list[mid:])
	result = merge(left_list, right_list)
	return result

t = input()
t = int(t)
arr = []
for x in range(t):
    n = input()
    s = input()
    arr.append([int(i) for i in s.split()])

out = [0] * t
for x in range(t):
    arr[x] = mergesort(arr[x])
    k = len(arr[x])
    out[x] = arr[x][-1] + (sum(arr[x], -arr[x][-1]))/float((k-1))

for i in out: print(i)
