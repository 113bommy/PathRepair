a = int(input())
b = list(map(int, input().split()))
c = int(input())
d = list(map(int, input().split()))
b.sort()
d.sort()
final = 0
for i in range(a):
	for j in range(c):
		if abs(b[i] - d[j]) < 2:
			final += 1
			d[1] == 9999
			break
print(final)