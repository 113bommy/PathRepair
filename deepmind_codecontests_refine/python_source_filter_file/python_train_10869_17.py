n = int(input())
l = [int(x) for x in input().split()]
min = abs(l[0]-l[-1])
a = [1,5]
for i in range(n-1):
	if abs(l[i+1] - l[i]) < min:
		min = abs(l[i+1] - l[i])
		a = [i+2,i+1]
print(*a)
	