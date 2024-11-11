def rev(a):
	return a[::-1]

def perm(s,n):
	if (len(s)-n)%2:
		return s[n-1:]+s[:n-1]
	else:
		return s[n-1:]+rev(s[:n-1])
	# for k in range(len(s)-n+1):
	# 	s = s[:k]+rev(s[k:k+n])+s[k+n:]
	# return s


def calc(s):
	if len(s) < 2:
		return (s,1)
	li = []
	d = min(s)
	ran = []
	for k in range(len(s)):
		if s[k] == d:	
			ran.append(k+1)
	if len(ran) == len(s):
		return (s,1)

	for j in ran:
		# print(perm(s,j),j)
		li.append((perm(s,j),j))
	# print(li)
	# sorted(li)
	li.sort()
	mini = li[0][0]
	anss = li[0][1]
	# print(li[0])
	for j in li:
		if mini == j[0]:
			anss = min(anss,j[1])
		else:
			break
	return (li[0][0],anss)



for i in range(int(input())):
	n = int(input())
	arr = input()
	
	# perm(arr,n)
	# for j in range()
	temp = calc(arr)
	print(temp[0])
	print(temp[1])
