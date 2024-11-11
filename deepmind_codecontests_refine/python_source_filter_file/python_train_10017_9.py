n = int(input())
l = [int(i) for i in input().split()]
k = 0
for i in l:
	if (n - i) % 2 == 0:
		k += 1
print(k)