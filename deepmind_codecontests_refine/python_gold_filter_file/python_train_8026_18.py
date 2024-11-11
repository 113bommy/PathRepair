n = int(input())
a = 0

for i in range(n):
	b, c = map(int, input().split())
	if b + c > a:
		a = b + c

print(a)