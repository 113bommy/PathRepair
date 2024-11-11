n = int(input())
a = list(map(int, input().split()))
a_sort = sorted(a, key=int)
j = 1
for i in range(n):
	if a_sort[i] > j:
		j += 1
print(j + 1)
