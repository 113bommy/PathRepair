n = int(input())

s = set(range(1, n))
p = set(list(map(int, input().split()[1:])))
q = set(list(map(int, input().split()[1:])))

if bool(s.difference(p.union(q))):
	print("Oh, my keyboard!")
else:
	print("I become the guy.")