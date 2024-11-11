n, m = map(int, input().split())
possible = set()
for _ in range(n):
	lst = list(map(int, input().split()))
	for element in lst[1:]:
		possible.add(element)
for i in range(1, m+1):
	if i not in possible:
		exit(print("NO"))
print("YES")