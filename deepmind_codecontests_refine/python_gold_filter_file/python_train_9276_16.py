# map(int, input().split())
# int(input())
n = int(input())
s = set(range(1, 101))
for i in range(n):
	curr = set(list(map(int, input().split()))[1:])
	scp = s
	s = set()
	for el in scp:
		if el in curr:
			s.add(el)

for el in s:
	print(el, end=" ")
print()
