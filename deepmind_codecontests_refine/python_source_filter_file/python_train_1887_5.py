from collections import Counter
n = int(input())
a = sorted(list(Counter([int(i) for i in input().split()]).values()),reverse = True)
mx = 0
c = a[0]
print(a)
for i,j in enumerate(a):
	print(i,j,c)
	t = min(c//(2**i),j)
	# print(t)
	if t == 0:
		break
	c = t * 2**i
	# print(c)
	arr = [c//(2**j) for j in range(i+1)]
	mx = max(sum(arr),mx)
print(mx)