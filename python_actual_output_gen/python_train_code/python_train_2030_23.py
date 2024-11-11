n = int(input())
first = (input())
last = (input())
count = 0
for i in range(n):
	a = int(first[i])
	b = int(last[i])
	count += min(10-max(a,b)+min(a,b),abs(a-b))
	print(min(10-max(a,b)+min(a,b),abs(a-b)),end=' ')
print()
print(count)